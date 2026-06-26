
#pragma once
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include "traceweft/record.hpp"
namespace traceweft {
struct TraceStats {
 uint64_t records=0;
 uint64_t payloadBytes=0;
 uint64_t firstTimestamp=0;
 uint64_t lastTimestamp=0;
 std::map<std::string,uint64_t> byService;
 std::map<uint16_t,uint64_t> byLevel;
 std::map<uint32_t,uint64_t> byStream;
 }
;
TraceStats ComputeStats(const std::vector<EventRecord>& records);
std::string FormatStats(const TraceStats& stats);
std::vector<std::pair<std::string,uint64_t>> TopServices(const TraceStats& stats, size_t limit);
std::vector<std::pair<uint16_t,uint64_t>> LevelHistogram(const TraceStats& stats);
}
