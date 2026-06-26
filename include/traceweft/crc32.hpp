
#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
namespace traceweft {
 uint32_t Crc32(const uint8_t* data, size_t size);
 uint32_t Crc32(const std::vector<uint8_t>& data);
 }
