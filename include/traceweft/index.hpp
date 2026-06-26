
#pragma once
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include "traceweft/record.hpp"
namespace traceweft {
struct TraceIndex {
 std::map<uint32_t,std::vector<size_t>> byStream;
 std::map<std::string,std::vector<size_t>> byService;
 std::map<uint16_t,std::vector<size_t>> byLevel;
 }
;
TraceIndex BuildIndex(const std::vector<EventRecord>& records);
std::vector<size_t> LookupService(const TraceIndex& index, const std::string& service);
std::vector<size_t> LookupStream(const TraceIndex& index, uint32_t stream);
std::vector<size_t> IntersectPostings(std::vector<size_t> a, std::vector<size_t> b);
std::string DescribeIndex(const TraceIndex& index);
}
