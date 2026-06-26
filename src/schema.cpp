
#include "traceweft/schema.hpp"
#include "traceweft/error.hpp"
#include "traceweft/varint.hpp"
#include <algorithm>
#include <set>
#include <sstream>
namespace traceweft {
static std::string trim(const std::string& s){
 size_t a=s.find_first_not_of(" \t\r\n");
 if(a==std::string::npos) return {
}
;
 size_t b=s.find_last_not_of(" \t\r\n");
 return s.substr(a,b-a+1);
 }
Schema ParseSchemaText(const std::string& text){
 Schema schema;
 std::istringstream in(text);
 std::string line;
 StreamDef* current=nullptr;
 while(std::getline(in,line)){
 line=trim(line);
 if(line.empty()||line[0]=='#') continue;
 std::istringstream ls(line);
 std::string word;
 ls>>word;
 if(word=="version"){
 ls>>schema.version;
 }
 else if(word=="stream"){
 StreamDef s;
 ls>>s.id>>s.name>>s.service;
 if(s.name.empty()) throw FormatError("stream line missing name");
 schema.streams.push_back(s);
 current=&schema.streams.back();
 }
 else if(word=="field"){
 if(!current) throw FormatError("field without stream");
 FieldDef f;
 std::string opt;
 ls>>f.id>>f.name>>f.type>>opt;
 f.optional=(opt=="optional");
 if(f.name.empty()||f.type.empty()) throw FormatError("field line missing parts");
 current->fields.push_back(f);
 }
 else {
 throw FormatError("unknown schema directive: "+word);
 }
 }
 return schema;
 }
std::string FormatSchemaText(const Schema& schema){
 std::ostringstream os;
 os<<"version "<<schema.version<<"\n";
 for(const auto& s:schema.streams){
 os<<"stream "<<s.id<<" "<<s.name<<" "<<s.service<<"\n";
 for(const auto& f:s.fields){
 os<<"field "<<f.id<<" "<<f.name<<" "<<f.type<<(f.optional?" optional":"")<<"\n";
 }
 }
 return os.str();
 }
Schema ParseSchemaBlock(const std::vector<uint8_t>& bytes){
 ByteReader r(bytes);
 Schema s;
 if(r.remaining()<4) return s;
 s.version=r.readU32();
 uint64_t streams=ReadVarU64(r);
 if(streams>4096) throw FormatError("too many streams in schema");
 for(uint64_t i=0;i<streams;i++){
 StreamDef st;
 st.id=r.readU32();
 uint64_t nlen=ReadVarU64(r);
 if(nlen>4096) throw FormatError("stream name too long");
 st.name=r.readString(size_t(nlen));
 uint64_t slen=ReadVarU64(r);
 if(slen>4096) throw FormatError("service name too long");
 st.service=r.readString(size_t(slen));
 uint64_t fields=ReadVarU64(r);
 if(fields>8192) throw FormatError("too many fields");
 for(uint64_t j=0;j<fields;j++){
 FieldDef f;
 f.id=r.readU32();
 uint64_t k=ReadVarU64(r);
 if(k>2048) throw FormatError("field name too long");
 f.name=r.readString(size_t(k));
 uint64_t t=ReadVarU64(r);
 if(t>2048) throw FormatError("field type too long");
 f.type=r.readString(size_t(t));
 f.optional=r.readU8()!=0;
 st.fields.push_back(f);
 }
 s.streams.push_back(st);
 }
 return s;
 }
std::vector<uint8_t> SerializeSchemaBlock(const Schema& schema){
 ByteWriter w;
 w.writeU32(schema.version);
 WriteVarU64(w, schema.streams.size());
 for(const auto& s:schema.streams){
 w.writeU32(s.id);
 WriteVarU64(w,s.name.size());
 w.writeString(s.name);
 WriteVarU64(w,s.service.size());
 w.writeString(s.service);
 WriteVarU64(w,s.fields.size());
 for(const auto& f:s.fields){
 w.writeU32(f.id);
 WriteVarU64(w,f.name.size());
 w.writeString(f.name);
 WriteVarU64(w,f.type.size());
 w.writeString(f.type);
 w.writeU8(f.optional?1:0);
 }
 }
 return w.take();
 }
const StreamDef* FindStream(const Schema& schema, uint32_t id){
 for(const auto& s:schema.streams) if(s.id==id) return &s;
 return nullptr;
 }
std::vector<std::string> ValidateSchema(const Schema& schema){
 std::vector<std::string> issues;
 std::set<uint32_t> ids;
 for(const auto& s:schema.streams){
 if(s.name.empty()) issues.push_back("stream with empty name");
 if(!ids.insert(s.id).second) issues.push_back("duplicate stream id "+std::to_string(s.id));
 std::set<uint32_t> fieldIds;
 for(const auto& f:s.fields){
 if(f.name.empty()) issues.push_back("empty field in stream "+s.name);
 if(!fieldIds.insert(f.id).second) issues.push_back("duplicate field id in "+s.name);
 if(f.type!="string"&&f.type!="u64"&&f.type!="i64"&&f.type!="bytes"&&f.type!="bool") issues.push_back("unknown field type "+f.type);
 }
 }
 return issues;
 }
}
