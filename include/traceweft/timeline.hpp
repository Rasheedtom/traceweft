
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "traceweft/record.hpp"
namespace traceweft {
struct TimeBucket {
 uint64_t start=0;
 uint64_t end=0;
 uint64_t count=0;
 uint64_t errors=0;
 }
;
std::vector<TimeBucket> BuildTimeline(const std::vector<EventRecord>& records, uint64_t bucketWidth);
std::string FormatTimeline(const std::vector<TimeBucket>& buckets);
std::vector<EventRecord> SliceByTime(const std::vector<EventRecord>& records, uint64_t begin, uint64_t end);
uint64_t SuggestBucketWidth(uint64_t first, uint64_t last, size_t targetBuckets);
}
