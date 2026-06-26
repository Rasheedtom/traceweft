
#include "traceweft/csv.hpp"
#include <sstream>
namespace traceweft {
std::string CsvEscape(const std::string& text){
 bool q=false;
 for(char c:text) if(c==','||c=='"'||c=='\n'||c=='\r') q=true;
 if(!q) return text;
 std::string out="\"";
 for(char c:text){
 if(c=='"') out += "\"\"";
 else out.push_back(c);
 }
 out.push_back('"');
 return out;
 }
std::string RecordsToCsv(const std::vector<EventRecord>& records){
 std::ostringstream os;
 os<<"timestamp,stream,level,service,name,payload_bytes\n";
 for(const auto&r:records) os<<r.timestamp<<","<<r.stream<<","<<r.level<<","<<CsvEscape(r.service)<<","<<CsvEscape(r.name)<<","<<r.payload.size()<<"\n";
 return os.str();
 }
std::vector<EventRecord> RecordsFromCsv(const std::string& csv){
 std::vector<EventRecord> records;
 std::istringstream in(csv);
 std::string line;
 std::getline(in,line);
 while(std::getline(in,line)){
 std::vector<std::string> cells;
 std::string cur;
 bool q=false;
 for(size_t i=0;i<line.size();i++){
 char c=line[i];
 if(q && c=='"' && i+1<line.size() && line[i+1]=='"'){
 cur.push_back('"');
 i++;
 }
 else if(c=='"'){
 q=!q;
 }
 else if(c==',' && !q){
 cells.push_back(cur);
 cur.clear();
 }
 else cur.push_back(c);
 }
 cells.push_back(cur);
 if(cells.size()>=5){
 EventRecord r;
 try{
 r.timestamp=std::stoull(cells[0]);
 r.stream=std::stoul(cells[1]);
 r.level=uint16_t(std::stoul(cells[2]));
 }
catch(...){
 continue;
 }
 r.service=cells[3];
 r.name=cells[4];
 records.push_back(r);
 }
 }
 return records;
 }
}
