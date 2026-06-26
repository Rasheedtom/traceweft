
#pragma once
#include <string>
#include <vector>
#include "traceweft/frame.hpp"
#include "traceweft/schema.hpp"
namespace traceweft {
struct TraceFile {
 FrameHeader header;
 Schema schema;
 std::vector<Segment> segments;
 std::vector<std::string> warnings;
 }
;
TraceFile ReadTraceBytes(const std::vector<uint8_t>& bytes);
TraceFile ReadTraceFile(const std::string& path);
std::vector<uint8_t> WriteTraceBytes(const Schema& schema, const std::vector<Segment>& segments);
void WriteTraceFile(const std::string& path, const Schema& schema, const std::vector<Segment>& segments);
std::vector<EventRecord> FlattenRecords(const TraceFile& trace);
std::string InspectTrace(const TraceFile& trace);
std::vector<std::string> VerifyTrace(const TraceFile& trace);
}
