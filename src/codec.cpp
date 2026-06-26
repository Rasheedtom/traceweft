
#include "traceweft/codec.hpp"
#include "traceweft/byte_reader.hpp"
#include "traceweft/error.hpp"
#include <algorithm>
namespace traceweft {
std::string CodecName(PayloadCodec c){
 switch(c){
 case PayloadCodec::Raw:return "raw";
 case PayloadCodec::Rle:return "rle";
 case PayloadCodec::XorDelta:return "xordelta";
 case PayloadCodec::PackBits:return "packbits";
 }
 return "unknown";
 }
PayloadCodec ParseCodec(uint8_t id){
 switch(id){
 case 0:return PayloadCodec::Raw;
 case 1:return PayloadCodec::Rle;
 case 2:return PayloadCodec::XorDelta;
 case 3:return PayloadCodec::PackBits;
 default: throw FormatError("unknown payload codec");
 }
 }
std::vector<uint8_t> EncodeRle(const std::vector<uint8_t>& input){
 ByteWriter w;
 for(size_t i=0;i<input.size();){
 uint8_t v=input[i];
 size_t run=1;
 while(i+run<input.size() && input[i+run]==v && run<255) run++;
 w.writeU8(uint8_t(run));
 w.writeU8(v);
 i+=run;
 }
 return w.take();
 }
std::vector<uint8_t> DecodeRle(const std::vector<uint8_t>& input){
 ByteReader r(input);
 std::vector<uint8_t> out;
 while(!r.empty()){
 uint8_t count=r.readU8();
 uint8_t value=r.readU8();
 out.insert(out.end(), count, value);
 }
 return out;
 }
std::vector<uint8_t> EncodeXorDelta(const std::vector<uint8_t>& input){
 std::vector<uint8_t> out;
 out.reserve(input.size());
 uint8_t prev=0;
 for(auto b:input){
 out.push_back(b ^ prev);
 prev=b;
 }
 return out;
 }
std::vector<uint8_t> DecodeXorDelta(const std::vector<uint8_t>& input){
 std::vector<uint8_t> out;
 out.reserve(input.size());
 uint8_t prev=0;
 for(auto b:input){
 uint8_t v=b^prev;
 out.push_back(v);
 prev=v;
 }
 return out;
 }
std::vector<uint8_t> EncodePackBits(const std::vector<uint8_t>& input){
 ByteWriter w;
 for(size_t i=0;i<input.size();){
 size_t literalStart=i;
 size_t literalCount=0;
 while(i<input.size() && literalCount<127){
 if(i+2<input.size() && input[i]==input[i+1] && input[i]==input[i+2]) break;
 i++;
 literalCount++;
 }
 if(literalCount){
 w.writeU8(uint8_t(literalCount));
 for(size_t j=0;j<literalCount;j++) w.writeU8(input[literalStart+j]);
 }
 if(i<input.size()){
 uint8_t v=input[i];
 size_t run=1;
 while(i+run<input.size() && input[i+run]==v && run<127) run++;
 w.writeU8(uint8_t(0x80|run));
 w.writeU8(v);
 i+=run;
 }
 }
 return w.take();
 }
std::vector<uint8_t> DecodePackBits(const std::vector<uint8_t>& input){
 ByteReader r(input);
 std::vector<uint8_t> out;
 while(!r.empty()){
 uint8_t tag=r.readU8();
 if(tag & 0x80){
 size_t n=tag&0x7f;
 uint8_t v=r.readU8();
 out.insert(out.end(), n, v);
 }
 else {
 size_t n=tag;
 auto lit=r.readBytes(n);
 out.insert(out.end(), lit.begin(), lit.end());
 }
 }
 return out;
 }
std::vector<uint8_t> EncodePayload(PayloadCodec codec, const std::vector<uint8_t>& input){
 switch(codec){
 case PayloadCodec::Raw:return input;
 case PayloadCodec::Rle:return EncodeRle(input);
 case PayloadCodec::XorDelta:return EncodeXorDelta(input);
 case PayloadCodec::PackBits:return EncodePackBits(input);
 }
 return input;
 }
std::vector<uint8_t> DecodePayload(PayloadCodec codec, const std::vector<uint8_t>& input){
 switch(codec){
 case PayloadCodec::Raw:return input;
 case PayloadCodec::Rle:return DecodeRle(input);
 case PayloadCodec::XorDelta:return DecodeXorDelta(input);
 case PayloadCodec::PackBits:return DecodePackBits(input);
 }
 return input;
 }
}
