
#include "traceweft/timeline.hpp"
#include <algorithm>
#include <sstream>
namespace traceweft {
uint64_t SuggestBucketWidth(uint64_t first, uint64_t last, size_t targetBuckets){
 if(last<=first || targetBuckets==0) return 1;
 uint64_t span=last-first;
 uint64_t w=span/targetBuckets;
 return w? w:1;
 }
std::vector<TimeBucket> BuildTimeline(const std::vector<EventRecord>& records, uint64_t bucketWidth){
 if(records.empty()) return {
}
;
 if(bucketWidth==0) bucketWidth=1;
 uint64_t first=records.front().timestamp, last=records.front().timestamp;
 for(const auto&r:records){
 first=std::min(first,r.timestamp);
 last=std::max(last,r.timestamp);
 }
 size_t count=size_t((last-first)/bucketWidth)+1;
 if(count>100000) count=100000;
 std::vector<TimeBucket> b(count);
 for(size_t i=0;i<b.size();i++){
 b[i].start=first+i*bucketWidth;
 b[i].end=b[i].start+bucketWidth;
 }
 for(const auto&r:records){
 size_t idx=size_t((r.timestamp-first)/bucketWidth);
 if(idx>=b.size()) idx=b.size()-1;
 b[idx].count++;
 if(r.level>=4) b[idx].errors++;
 }
 return b;
 }
std::string FormatTimeline(const std::vector<TimeBucket>& buckets){
 std::ostringstream os;
 for(const auto& b:buckets){
 os<<b.start<<"-"<<b.end<<" count="<<b.count;
 if(b.errors) os<<" errors="<<b.errors;
 os<<"\n";
 }
 return os.str();
 }
std::vector<EventRecord> SliceByTime(const std::vector<EventRecord>& records, uint64_t begin, uint64_t end){
 std::vector<EventRecord> out;
 for(const auto&r:records) if(r.timestamp>=begin && r.timestamp<end) out.push_back(r);
 return out;
 }
}
