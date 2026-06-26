#include "traceweft/frame.hpp"
#include <cstdint>
#include <vector>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  std::vector<uint8_t> bytes(data, data + size);
  try { (void)traceweft::ParseSegmentTable(bytes); } catch (...) {}
  try { (void)traceweft::ParseSegmentRecords(bytes); } catch (...) {}
  return 0;
}
