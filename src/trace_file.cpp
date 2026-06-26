
#include "traceweft/trace_file.hpp"
#include "traceweft/varint.hpp"
#include "traceweft/codec.hpp"
#include "traceweft/crc32.hpp"
#include "traceweft/error.hpp"
#include <fstream>
#include <sstream>
namespace traceweft {
static std::vector<uint8_t> ReadAll(const std::string& path){
 std::ifstream in(path, std::ios::binary);
 if(!in) throw IoError("cannot open "+path);
 in.seekg(0,std::ios::end);
 auto n=in.tellg();
 if(n<0) throw IoError("cannot size "+path);
 in.seekg(0);
 std::vector<uint8_t> b(static_cast<size_t>(n));
 if(!b.empty()) in.read(reinterpret_cast<char*>(b.data()), b.size());
 return b;
 }
static void WriteAll(const std::string& path, const std::vector<uint8_t>& bytes){
 std::ofstream out(path, std::ios::binary);
 if(!out) throw IoError("cannot write "+path);
 if(!bytes.empty()) out.write(reinterpret_cast<const char*>(bytes.data()), bytes.size());
 }
TraceFile ReadTraceBytes(const std::vector<uint8_t>& bytes){
 if(bytes.size()<36) throw FormatError("file too small");
 TraceFile file;
 std::vector<uint8_t> headerBytes(bytes.begin(), bytes.begin()+36);
 file.header=ParseFrameHeader(headerBytes);
 if(file.header.fileSize && file.header.fileSize != bytes.size()) file.warnings.push_back("header size does not match actual size");
 if(file.header.schemaOffset>=bytes.size() || file.header.segmentTableOffset>=bytes.size()) throw FormatError("table offset outside file");
 if(file.header.schemaOffset > file.header.segmentTableOffset) throw FormatError("schema after segment table");
 uint64_t schemaLen=file.header.segmentTableOffset-file.header.schemaOffset;
 std::vector<uint8_t> schemaBlock(bytes.begin()+file.header.schemaOffset, bytes.begin()+file.header.segmentTableOffset);
 file.schema=ParseSchemaBlock(schemaBlock);
 ByteReader tr(bytes.data()+file.header.segmentTableOffset, bytes.size()-file.header.segmentTableOffset);
 uint64_t tableLen=ReadVarU64(tr);
 if(tableLen>bytes.size()-tr.offset()-file.header.segmentTableOffset) throw FormatError("segment table length outside file");
 auto tableBytes=tr.readBytes(static_cast<size_t>(tableLen));
 auto infos=ParseSegmentTable(tableBytes);
 for(auto info: infos){
 if(info.offset > bytes.size() || info.size > bytes.size()-info.offset) throw FormatError("segment range outside file");
 std::vector<uint8_t> enc(bytes.begin()+info.offset, bytes.begin()+info.offset+info.size);
 if(info.crc && Crc32(enc)!=info.crc) file.warnings.push_back("segment crc mismatch");
 auto dec=DecodePayload(info.codec, enc);
 Segment seg;
 seg.info=info;
 seg.records=ParseSegmentRecords(dec);
 file.segments.push_back(std::move(seg));
 }
 return file;
 }
TraceFile ReadTraceFile(const std::string& path){
 return ReadTraceBytes(ReadAll(path));
 }
std::vector<uint8_t> WriteTraceBytes(const Schema& schema, const std::vector<Segment>& segments){
 std::vector<uint8_t> schemaBytes=SerializeSchemaBlock(schema);
 std::vector<std::vector<uint8_t>> encoded;
 std::vector<SegmentInfo> infos;
 uint64_t offset=36 + schemaBytes.size();
 std::vector<uint8_t> tablePlaceholder;
 for(const auto& s:segments){
 auto raw=SerializeSegmentRecords(s.records);
 auto enc=EncodePayload(s.info.codec, raw);
 encoded.push_back(enc);
 SegmentInfo inf=s.info;
 inf.size=enc.size();
 if(!s.records.empty()){
 inf.firstTimestamp=s.records.front().timestamp;
 inf.lastTimestamp=s.records.back().timestamp;
 inf.stream=s.records.front().stream;
 }
 inf.crc=Crc32(enc);
 infos.push_back(inf);
 }
 std::vector<uint8_t> table=SerializeSegmentTable(infos);
 ByteWriter tableWrapped;
 WriteVarU64(tableWrapped, table.size());
 tableWrapped.writeBytes(table);
 uint64_t segmentStart=36 + schemaBytes.size() + tableWrapped.bytes().size();
 for(size_t i=0;i<infos.size();i++){
 infos[i].offset=segmentStart;
 segmentStart += encoded[i].size();
 }
 table=SerializeSegmentTable(infos);
 ByteWriter tableWrapped2;
 WriteVarU64(tableWrapped2, table.size());
 tableWrapped2.writeBytes(table);
 FrameHeader h;
 h.schemaOffset=36;
 h.segmentTableOffset=36+schemaBytes.size();
 h.fileSize=36+schemaBytes.size()+tableWrapped2.bytes().size();
 for(auto& e:encoded) h.fileSize += e.size();
 ByteWriter out;
 out.writeBytes(SerializeFrameHeader(h));
 out.writeBytes(schemaBytes);
 out.writeBytes(tableWrapped2.bytes());
 for(auto& e:encoded) out.writeBytes(e);
 return out.take();
 }
void WriteTraceFile(const std::string& path, const Schema& schema, const std::vector<Segment>& segments){
 WriteAll(path, WriteTraceBytes(schema, segments));
 }
std::vector<EventRecord> FlattenRecords(const TraceFile& trace){
 std::vector<EventRecord> out;
 for(const auto& s:trace.segments) out.insert(out.end(), s.records.begin(), s.records.end());
 return out;
 }
std::string InspectTrace(const TraceFile& trace){
 std::ostringstream os;
 os<<"TraceWeft version "<<trace.header.version<<"\n";
 os<<"streams: "<<trace.schema.streams.size()<<"\n";
 os<<"segments: "<<trace.segments.size()<<"\n";
 size_t records=0;
 for(const auto& s:trace.segments) records+=s.records.size();
 os<<"records: "<<records<<"\n";
 for(const auto& s:trace.segments) os<<"  "<<DescribeSegment(s.info)<<" records="<<s.records.size()<<"\n";
 for(const auto& w:trace.warnings) os<<"warning: "<<w<<"\n";
 return os.str();
 }
std::vector<std::string> VerifyTrace(const TraceFile& trace){
 std::vector<std::string> issues=ValidateSchema(trace.schema);
 for(const auto& seg:trace.segments){
 uint64_t prev=0;
 bool first=true;
 for(const auto& rec:seg.records){
 if(!FindStream(trace.schema, rec.stream)) issues.push_back("record references unknown stream "+std::to_string(rec.stream));
 if(!first && rec.timestamp<prev) issues.push_back("records not sorted in segment");
 prev=rec.timestamp;
 first=false;
 }
 }
 for(const auto& w:trace.warnings) issues.push_back(w);
 return issues;
 }
}
