#include "traceweft/schema.hpp"
#include <cstdint>
#include <string>
#include <vector>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  std::vector<uint8_t> bytes(data, data + size);
  try { auto s = traceweft::ParseSchemaBlock(bytes); (void)traceweft::ValidateSchema(s); } catch (...) {}
  std::string text(reinterpret_cast<const char*>(data), size);
  try { auto s = traceweft::ParseSchemaText(text); (void)traceweft::FormatSchemaText(s); } catch (...) {}
  return 0;
}
