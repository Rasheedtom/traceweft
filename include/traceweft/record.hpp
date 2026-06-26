
#pragma once
#include <cstdint>
#include <map>
#include <string>
#include <vector>
namespace traceweft {
struct Attribute {
 std::string key;
 std::string value;
 }
;
struct EventRecord {
  uint64_t timestamp = 0;
  uint32_t stream = 0;
  uint16_t level = 0;
  uint16_t flags = 0;
  std::string service;
  std::string name;
  std::vector<uint8_t> payload;
  std::vector<Attribute> attributes;
}
;
std::string LevelName(uint16_t level);
bool HasFlag(const EventRecord& rec, uint16_t bit);
std::string RecordSummary(const EventRecord& rec);
std::map<std::string,std::string> AttributeMap(const EventRecord& rec);
}
