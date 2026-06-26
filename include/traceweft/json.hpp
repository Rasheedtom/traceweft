
#pragma once
#include <string>
#include <vector>
#include "traceweft/record.hpp"
#include "traceweft/schema.hpp"
#include "traceweft/trace_file.hpp"
namespace traceweft {
std::string JsonEscape(const std::string& text);
std::string RecordToJson(const EventRecord& rec);
std::string RecordsToJson(const std::vector<EventRecord>& records);
std::string SchemaToJson(const Schema& schema);
std::string TraceSummaryToJson(const TraceFile& trace);
}
