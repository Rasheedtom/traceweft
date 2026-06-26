#include "traceweft/query.hpp"
#include <cstdint>
#include <string>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  std::string expr(reinterpret_cast<const char*>(data), size);
  try { auto q = traceweft::ParseQuery(expr); (void)traceweft::ExplainQuery(q); } catch (...) {}
  return 0;
}
