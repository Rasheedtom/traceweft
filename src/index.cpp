
#include "traceweft/index.hpp"
#include <algorithm>
#include <sstream>
namespace traceweft {
TraceIndex BuildIndex(const std::vector<EventRecord>& records){
 TraceIndex idx;
 for(size_t i=0;i<records.size();i++){
 idx.byStream[records[i].stream].push_back(i);
 idx.byService[records[i].service].push_back(i);
 idx.byLevel[records[i].level].push_back(i);
 }
 return idx;
 }
std::vector<size_t> LookupService(const TraceIndex& index, const std::string& service){
 auto it=index.byService.find(service);
 return it==index.byService.end()?std::vector<size_t>{
}
:it->second;
 }
std::vector<size_t> LookupStream(const TraceIndex& index, uint32_t stream){
 auto it=index.byStream.find(stream);
 return it==index.byStream.end()?std::vector<size_t>{
}
:it->second;
 }
std::vector<size_t> IntersectPostings(std::vector<size_t> a, std::vector<size_t> b){
 std::sort(a.begin(),a.end());
 std::sort(b.begin(),b.end());
 std::vector<size_t> out;
 std::set_intersection(a.begin(),a.end(),b.begin(),b.end(),std::back_inserter(out));
 return out;
 }
std::string DescribeIndex(const TraceIndex& index){
 std::ostringstream os;
 os<<"streams="<<index.byStream.size()<<" services="<<index.byService.size()<<" levels="<<index.byLevel.size();
 return os.str();
 }
}
