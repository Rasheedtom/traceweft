
#include "traceweft/json.hpp"
#include <iomanip>
#include <sstream>
namespace traceweft {
std::string JsonEscape(const std::string& text){
 std::ostringstream os;
 for(unsigned char c:text){
 switch(c){
 case '"': os<<"\\\"";
 break;
 case '\\': os<<"\\\\";
 break;
 case '\n': os<<"\\n";
 break;
 case '\r': os<<"\\r";
 break;
 case '\t': os<<"\\t";
 break;
 default: if(c<32) os<<"\\u"<<std::hex<<std::setw(4)<<std::setfill('0')<<int(c)<<std::dec;
 else os<<char(c);
 }
 }
 return os.str();
 }
std::string RecordToJson(const EventRecord& rec){
 std::ostringstream os;
 os<<"{\"timestamp\":"<<rec.timestamp<<",\"stream\":"<<rec.stream<<",\"level\":"<<rec.level<<",\"levelName\":\""<<LevelName(rec.level)<<"\",\"service\":\""<<JsonEscape(rec.service)<<"\",\"name\":\""<<JsonEscape(rec.name)<<"\",\"payloadBytes\":"<<rec.payload.size()<<",\"attributes\":{";
 for(size_t i=0;i<rec.attributes.size();i++){
 if(i) os<<",";
 os<<"\""<<JsonEscape(rec.attributes[i].key)<<"\":\""<<JsonEscape(rec.attributes[i].value)<<"\"";
 }
 os<<"}}";
 return os.str();
 }
std::string RecordsToJson(const std::vector<EventRecord>& records){
 std::ostringstream os;
 os<<"[";
 for(size_t i=0;i<records.size();i++){
 if(i) os<<",";
 os<<RecordToJson(records[i]);
 }
 os<<"]";
 return os.str();
 }
std::string SchemaToJson(const Schema& schema){
 std::ostringstream os;
 os<<"{\"version\":"<<schema.version<<",\"streams\":[";
 for(size_t i=0;i<schema.streams.size();i++){
 const auto& s=schema.streams[i];
 if(i) os<<",";
 os<<"{\"id\":"<<s.id<<",\"name\":\""<<JsonEscape(s.name)<<"\",\"service\":\""<<JsonEscape(s.service)<<"\",\"fields\":[";
 for(size_t j=0;j<s.fields.size();j++){
 const auto& f=s.fields[j];
 if(j) os<<",";
 os<<"{\"id\":"<<f.id<<",\"name\":\""<<JsonEscape(f.name)<<"\",\"type\":\""<<JsonEscape(f.type)<<"\",\"optional\":"<<(f.optional?"true":"false")<<"}";
 }
 os<<"]}";
 }
 os<<"]}";
 return os.str();
 }
std::string TraceSummaryToJson(const TraceFile& trace){
 size_t records=0;
 for(const auto& s:trace.segments) records += s.records.size();
 std::ostringstream os;
 os<<"{\"version\":"<<trace.header.version<<",\"streams\":"<<trace.schema.streams.size()<<",\"segments\":"<<trace.segments.size()<<",\"records\":"<<records<<",\"warnings\":[";
 for(size_t i=0;i<trace.warnings.size();i++){
 if(i) os<<",";
 os<<"\""<<JsonEscape(trace.warnings[i])<<"\"";
 }
 os<<"]}";
 return os.str();
 }
}
