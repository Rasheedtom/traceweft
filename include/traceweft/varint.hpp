
#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include "traceweft/byte_reader.hpp"
namespace traceweft {
void WriteVarU64(ByteWriter& w, uint64_t v);
uint64_t ReadVarU64(ByteReader& r);
std::vector<uint8_t> EncodeVarU64(uint64_t v);
std::string ExplainVarint(const std::vector<uint8_t>& bytes);
}
