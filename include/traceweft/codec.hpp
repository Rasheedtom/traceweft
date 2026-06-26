
#pragma once
#include <cstdint>
#include <string>
#include <vector>
namespace traceweft {
enum class PayloadCodec : uint8_t {
 Raw=0, Rle=1, XorDelta=2, PackBits=3 }
;
std::string CodecName(PayloadCodec c);
PayloadCodec ParseCodec(uint8_t id);
std::vector<uint8_t> EncodePayload(PayloadCodec codec, const std::vector<uint8_t>& input);
std::vector<uint8_t> DecodePayload(PayloadCodec codec, const std::vector<uint8_t>& input);
std::vector<uint8_t> EncodeRle(const std::vector<uint8_t>& input);
std::vector<uint8_t> DecodeRle(const std::vector<uint8_t>& input);
std::vector<uint8_t> EncodeXorDelta(const std::vector<uint8_t>& input);
std::vector<uint8_t> DecodeXorDelta(const std::vector<uint8_t>& input);
std::vector<uint8_t> EncodePackBits(const std::vector<uint8_t>& input);
std::vector<uint8_t> DecodePackBits(const std::vector<uint8_t>& input);
}
