#include "traceweft/codec.hpp"
#include <cstdint>
#include <vector>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  if (size == 0) return 0;
  std::vector<uint8_t> bytes(data + 1, data + size);
  try { (void)traceweft::DecodePayload(traceweft::ParseCodec(data[0] % 4), bytes); } catch (...) {}
  return 0;
}
