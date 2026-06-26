#include "traceweft/trace_file.hpp"
#include <cstdint>
#include <vector>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  std::vector<uint8_t> bytes(data, data + size);
  try {
    auto tf = traceweft::ReadTraceBytes(bytes);
    (void)traceweft::InspectTrace(tf);
    (void)traceweft::VerifyTrace(tf);
  } catch (...) {}
  return 0;
}
