
#include "traceweft/record.hpp"
#include <sstream>
namespace traceweft {
std::string LevelName(uint16_t level){
 switch(level){
 case 0:return "trace";
 case 1:return "debug";
 case 2:return "info";
 case 3:return "warn";
 case 4:return "error";
 case 5:return "fatal";
 default:return "level-"+std::to_string(level);
 }
 }
bool HasFlag(const EventRecord& rec, uint16_t bit){
 return (rec.flags & bit) != 0;
 }
std::map<std::string,std::string> AttributeMap(const EventRecord& rec){
 std::map<std::string,std::string> m;
 for(const auto& a:rec.attributes) m[a.key]=a.value;
 return m;
 }
std::string RecordSummary(const EventRecord& rec){
 std::ostringstream os;
 os<<rec.timestamp<<" ["<<LevelName(rec.level)<<"] "<<rec.service<<":"<<rec.name;
 if(!rec.attributes.empty()) os<<" attrs="<<rec.attributes.size();
 if(!rec.payload.empty()) os<<" payload="<<rec.payload.size();
 return os.str();
 }
}
