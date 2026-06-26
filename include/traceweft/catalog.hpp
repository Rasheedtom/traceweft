#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "traceweft/record.hpp"
namespace traceweft {
struct CatalogEntry {
  std::string service;
  std::string event;
  uint16_t defaultLevel;
  std::string category;
  std::string description;
};
const std::vector<CatalogEntry>& BuiltinCatalog();
std::vector<CatalogEntry> CatalogByService(const std::string& service);
std::vector<CatalogEntry> SearchCatalog(const std::string& needle);
std::string ClassifyRecord(const EventRecord& record);
std::string CatalogSummary();
}
