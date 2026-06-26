
#include "traceweft/path.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
namespace traceweft {
std::vector<std::string> SplitPath(const std::string& path){
 std::vector<std::string> out;
 std::string cur;
 for(char c:path){
 if(c=='/'||c=='\\'){
 if(!cur.empty()){
 out.push_back(cur);
 cur.clear();
 }
 }
 else cur.push_back(c);
 }
 if(!cur.empty()) out.push_back(cur);
 return out;
 }
std::string JoinPathParts(const std::vector<std::string>& parts){
 std::string out;
 for(size_t i=0;i<parts.size();i++){
 if(i) out.push_back('/');
 out += parts[i];
 }
 return out;
 }
PathCheck NormalizeTracePath(const std::string& path){
 PathCheck c;
 c.absolute = !path.empty() && (path[0]=='/' || path[0]=='\\' || (path.size()>1 && path[1]==':'));
 for(unsigned char ch:path) if(ch<32 || ch==127) c.hasControl=true;
 auto raw=SplitPath(path);
 for(const auto& p:raw){
 if(p.empty() || p==".") continue;
 if(p==".."){
 c.hasParent=true;
 if(!c.parts.empty()) c.parts.pop_back();
 continue;
 }
 c.parts.push_back(p);
 }
 c.normalized=JoinPathParts(c.parts);
 c.safe=!c.absolute && !c.hasParent && !c.hasControl && !c.normalized.empty();
 return c;
 }
bool IsSafeRelativePath(const std::string& path){
 return NormalizeTracePath(path).safe;
 }
std::string CleanPathForDisplay(const std::string& path){
 std::string out;
 for(unsigned char ch:path){
 if(ch<32 || ch==127) out += '?';
 else if(ch=='\\') out += '/';
 else out += char(ch);
 }
 return out;
 }
}
