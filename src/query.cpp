
#include "traceweft/query.hpp"
#include "traceweft/error.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
namespace traceweft {
static std::string lower(std::string s){
 for(char& c:s)c=char(std::tolower(static_cast<unsigned char>(c)));
 return s;
 }
static std::string trim(const std::string& s){
 size_t a=s.find_first_not_of(" \t\n\r");
 if(a==std::string::npos)return{
}
;
 size_t b=s.find_last_not_of(" \t\n\r");
 return s.substr(a,b-a+1);
 }
static std::vector<std::string> splitWords(const std::string& expr){
 std::vector<std::string> out;
 std::string cur;
 bool quote=false;
 for(char c:expr){
 if(c=='\"'){
 quote=!quote;
 cur.push_back(c);
 }
 else if(std::isspace(static_cast<unsigned char>(c))&&!quote){
 if(!cur.empty()){
 out.push_back(cur);
 cur.clear();
 }
 }
 else cur.push_back(c);
 }
 if(quote) throw QueryError("unterminated quote");
 if(!cur.empty()) out.push_back(cur);
 return out;
 }
static std::string unquote(std::string v){
 v=trim(v);
 if(v.size()>=2 && v.front()=='\"' && v.back()=='\"') return v.substr(1,v.size()-2);
 return v;
 }
Query ParseQuery(const std::string& expr){
 Query q;
 auto words=splitWords(expr);
 if(words.empty()) return q;
 for(size_t i=0;i<words.size();){
 std::string w=lower(words[i]);
 if(w=="and"){
 q.matchAll=true;
 i++;
 continue;
 }
 if(w=="or"){
 q.matchAll=false;
 i++;
 continue;
 }
 if(w=="limit"){
 if(i+1>=words.size()) throw QueryError("limit requires value");
 q.limit=std::stoull(words[i+1]);
 i+=2;
 continue;
 }
 if(i+2>=words.size()) throw QueryError("incomplete predicate near "+words[i]);
 QueryPredicate p{
words[i],words[i+1],unquote(words[i+2])}
;
 q.terms.push_back(p);
 i+=3;
 }
 return q;
 }
static std::string fieldValue(const EventRecord& rec, const std::string& field){
 auto f=lower(field);
 if(f=="service") return rec.service;
 if(f=="name"||f=="event") return rec.name;
 if(f=="stream") return std::to_string(rec.stream);
 if(f=="level") return std::to_string(rec.level);
 if(f=="levelname") return LevelName(rec.level);
 if(f=="timestamp"||f=="time") return std::to_string(rec.timestamp);
 if(f.rfind("attr.",0)==0){
 auto key=field.substr(5);
 for(const auto& a:rec.attributes) if(a.key==key) return a.value;
 return {
}
;
 }
 return {
}
;
 }
static bool cmpNum(uint64_t a, const std::string& op, uint64_t b){
 if(op=="=") return a==b;
 if(op=="!=") return a!=b;
 if(op==">") return a>b;
 if(op==">=") return a>=b;
 if(op=="<") return a<b;
 if(op=="<=") return a<=b;
 return false;
 }
static bool cmpStr(const std::string& a, const std::string& op, const std::string& b){
 if(op=="=") return a==b;
 if(op=="!=") return a!=b;
 if(op=="~") return a.find(b)!=std::string::npos;
 if(op=="^=") return a.rfind(b,0)==0;
 if(op=="$=") return a.size()>=b.size() && a.compare(a.size()-b.size(),b.size(),b)==0;
 return false;
 }
bool MatchesQuery(const EventRecord& rec, const Query& q){
 if(q.terms.empty()) return true;
 bool result=q.matchAll;
 for(const auto& t:q.terms){
 std::string fv=fieldValue(rec,t.field);
 bool term=false;
 if(t.field=="level"||t.field=="stream"||t.field=="timestamp"||t.field=="time"){
 try{
 term=cmpNum(std::stoull(fv),t.op,std::stoull(t.value));
 }
catch(...){
 term=false;
 }
 }
 else term=cmpStr(fv,t.op,t.value);
 if(q.matchAll) result = result && term;
 else result = result || term;
 }
 return result;
 }
std::vector<EventRecord> FilterRecords(const std::vector<EventRecord>& records, const Query& q){
 std::vector<EventRecord> out;
 for(const auto& r:records){
 if(MatchesQuery(r,q)){
 out.push_back(r);
 if(q.limit && out.size()>=q.limit) break;
 }
 }
 return out;
 }
std::string ExplainQuery(const Query& q){
 std::ostringstream os;
 os<<(q.matchAll?"all":"any")<<" terms="<<q.terms.size();
 for(const auto& t:q.terms) os<<" ["<<t.field<<" "<<t.op<<" "<<t.value<<"]";
 if(q.limit) os<<" limit="<<q.limit;
 return os.str();
 }
}
