
#include "traceweft/stats.hpp"
#include <algorithm>
#include <sstream>
namespace traceweft {
TraceStats ComputeStats(const std::vector<EventRecord>& records){
 TraceStats s;
 s.records=records.size();
 bool first=true;
 for(const auto& r:records){
 s.payloadBytes += r.payload.size();
 s.byService[r.service]++;
 s.byLevel[r.level]++;
 s.byStream[r.stream]++;
 if(first){
 s.firstTimestamp=s.lastTimestamp=r.timestamp;
 first=false;
 }
 else {
 s.firstTimestamp=std::min(s.firstTimestamp,r.timestamp);
 s.lastTimestamp=std::max(s.lastTimestamp,r.timestamp);
 }
 }
 return s;
 }
std::string FormatStats(const TraceStats& s){
 std::ostringstream os;
 os<<"records: "<<s.records<<"\n";
 os<<"payload bytes: "<<s.payloadBytes<<"\n";
 os<<"time range: "<<s.firstTimestamp<<".."<<s.lastTimestamp<<"\n";
 os<<"services:\n";
 for(auto& kv:s.byService) os<<"  "<<kv.first<<": "<<kv.second<<"\n";
 os<<"levels:\n";
 for(auto& kv:s.byLevel) os<<"  "<<LevelName(kv.first)<<": "<<kv.second<<"\n";
 return os.str();
 }
std::vector<std::pair<std::string,uint64_t>> TopServices(const TraceStats& stats, size_t limit){
 std::vector<std::pair<std::string,uint64_t>> v(stats.byService.begin(), stats.byService.end());
 std::sort(v.begin(), v.end(), [](auto&a,auto&b){
 return a.second>b.second || (a.second==b.second && a.first<b.first); }
);
 if(v.size()>limit) v.resize(limit);
 return v;
 }
std::vector<std::pair<uint16_t,uint64_t>> LevelHistogram(const TraceStats& stats){
 std::vector<std::pair<uint16_t,uint64_t>> v(stats.byLevel.begin(), stats.byLevel.end());
 std::sort(v.begin(), v.end());
 return v;
 }
}
