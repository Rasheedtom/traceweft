
#include "traceweft/crc32.hpp"
namespace traceweft {
uint32_t Crc32(const uint8_t* data, size_t size){
 uint32_t crc=0xffffffffu;
 for(size_t i=0;i<size;i++){
 crc ^= data[i];
 for(int b=0;b<8;b++){
 uint32_t mask = 0u - (crc & 1u);
 crc = (crc >> 1) ^ (0xedb88320u & mask);
 }
 }
 return ~crc;
 }
uint32_t Crc32(const std::vector<uint8_t>& data){
 return Crc32(data.data(), data.size());
 }
}
