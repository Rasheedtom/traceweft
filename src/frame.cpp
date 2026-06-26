
#include "traceweft/frame.hpp"
#include "traceweft/byte_reader.hpp"
#include "traceweft/crc32.hpp"
#include "traceweft/error.hpp"
#include "traceweft/varint.hpp"
#include <sstream>
namespace traceweft {
static constexpr uint32_t kTraceMagic = 0x54465754u;
FrameHeader ParseFrameHeader(const std::vector<uint8_t>& bytes){
 ByteReader r(bytes);
 FrameHeader h;
 h.magic=r.readU32();
 if(h.magic!=kTraceMagic) throw FormatError("not a TraceWeft file");
 h.version=r.readU16();
 h.flags=r.readU16();
 h.schemaOffset=r.readU64();
 h.segmentTableOffset=r.readU64();
 h.fileSize=r.readU64();
 h.headerCrc=r.readU32();
 if(h.version==0 || h.version>9) throw FormatError("unsupported TraceWeft version");
 return h;
 }
std::vector<uint8_t> SerializeFrameHeader(const FrameHeader& h){
 ByteWriter w;
 w.writeU32(kTraceMagic);
 w.writeU16(h.version);
 w.writeU16(h.flags);
 w.writeU64(h.schemaOffset);
 w.writeU64(h.segmentTableOffset);
 w.writeU64(h.fileSize);
 w.writeU32(h.headerCrc);
 return w.take();
 }
std::vector<SegmentInfo> ParseSegmentTable(const std::vector<uint8_t>& bytes){
 ByteReader r(bytes);
 uint64_t count=ReadVarU64(r);
 if(count>1000000) throw FormatError("too many segments");
 std::vector<SegmentInfo> out;
 out.reserve(static_cast<size_t>(count));
 for(uint64_t i=0;i<count;i++){
 SegmentInfo s;
 s.offset=r.readU64();
 s.size=r.readU64();
 s.firstTimestamp=r.readU64();
 s.lastTimestamp=r.readU64();
 s.stream=r.readU32();
 s.codec=ParseCodec(r.readU8());
 s.crc=r.readU32();
 if(s.lastTimestamp<s.firstTimestamp) throw FormatError("segment timestamp range is inverted");
 out.push_back(s);
 }
 return out;
 }
std::vector<uint8_t> SerializeSegmentTable(const std::vector<SegmentInfo>& segments){
 ByteWriter w;
 WriteVarU64(w, segments.size());
 for(const auto& s:segments){
 w.writeU64(s.offset);
 w.writeU64(s.size);
 w.writeU64(s.firstTimestamp);
 w.writeU64(s.lastTimestamp);
 w.writeU32(s.stream);
 w.writeU8(static_cast<uint8_t>(s.codec));
 w.writeU32(s.crc);
 }
 return w.take();
 }
std::vector<EventRecord> ParseSegmentRecords(const std::vector<uint8_t>& bytes){
 ByteReader r(bytes);
 uint64_t n=ReadVarU64(r);
 if(n>2000000) throw FormatError("too many records in segment");
 std::vector<EventRecord> records;
 records.reserve(static_cast<size_t>(n));
 for(uint64_t i=0;i<n;i++){
 EventRecord e;
 e.timestamp=r.readU64();
 e.stream=r.readU32();
 e.level=r.readU16();
 e.flags=r.readU16();
 uint64_t slen=ReadVarU64(r);
 if(slen>4096) throw FormatError("service too long");
 e.service=r.readString(static_cast<size_t>(slen));
 uint64_t nlen=ReadVarU64(r);
 if(nlen>4096) throw FormatError("event name too long");
 e.name=r.readString(static_cast<size_t>(nlen));
 uint64_t plen=ReadVarU64(r);
 if(plen>16777216) throw FormatError("payload too large");
 e.payload=r.readBytes(static_cast<size_t>(plen));
 uint64_t attrs=ReadVarU64(r);
 if(attrs>4096) throw FormatError("too many attributes");
 for(uint64_t a=0;a<attrs;a++){
 Attribute at;
 uint64_t k=ReadVarU64(r);
 if(k>1024) throw FormatError("attribute key too long");
 at.key=r.readString(size_t(k));
 uint64_t v=ReadVarU64(r);
 if(v>8192) throw FormatError("attribute value too long");
 at.value=r.readString(size_t(v));
 e.attributes.push_back(at);
 }
 records.push_back(std::move(e));
 }
 return records;
 }
std::vector<uint8_t> SerializeSegmentRecords(const std::vector<EventRecord>& records){
 ByteWriter w;
 WriteVarU64(w, records.size());
 for(const auto& e:records){
 w.writeU64(e.timestamp);
 w.writeU32(e.stream);
 w.writeU16(e.level);
 w.writeU16(e.flags);
 WriteVarU64(w,e.service.size());
 w.writeString(e.service);
 WriteVarU64(w,e.name.size());
 w.writeString(e.name);
 WriteVarU64(w,e.payload.size());
 w.writeBytes(e.payload);
 WriteVarU64(w,e.attributes.size());
 for(const auto& a:e.attributes){
 WriteVarU64(w,a.key.size());
 w.writeString(a.key);
 WriteVarU64(w,a.value.size());
 w.writeString(a.value);
 }
 }
 return w.take();
 }
std::string DescribeSegment(const SegmentInfo& s){
 std::ostringstream os;
 os<<"segment stream="<<s.stream<<" offset="<<s.offset<<" size="<<s.size<<" codec="<<CodecName(s.codec)<<" time="<<s.firstTimestamp<<".."<<s.lastTimestamp;
 return os.str();
 }
}
