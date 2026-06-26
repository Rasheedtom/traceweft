
#pragma once
#include <string>
#include <vector>
#include "traceweft/record.hpp"
namespace traceweft {
std::string CsvEscape(const std::string& text);
std::string RecordsToCsv(const std::vector<EventRecord>& records);
std::vector<EventRecord> RecordsFromCsv(const std::string& csv);
}
