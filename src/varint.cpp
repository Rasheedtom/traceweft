
#include "traceweft/varint.hpp"
#include "traceweft/error.hpp"
#include <sstream>
namespace traceweft {
void WriteVarU64(ByteWriter& w, uint64_t v){
 while(v >= 0x80){
 w.writeU8(uint8_t(v) | 0x80);
 v >>= 7;
 }
 w.writeU8(uint8_t(v));
 }
uint64_t ReadVarU64(ByteReader& r){
 uint64_t value=0;
 int shift=0;
 for(int i=0;i<10;i++){
 uint8_t b=r.readU8();
 value |= uint64_t(b & 0x7f) << shift;
 if((b & 0x80)==0) return value;
 shift += 7;
 }
 throw FormatError("varint is longer than 10 bytes");
 }
std::vector<uint8_t> EncodeVarU64(uint64_t v){
 ByteWriter w;
 WriteVarU64(w,v);
 return w.take();
 }
std::string ExplainVarint(const std::vector<uint8_t>& bytes){
 std::ostringstream os;
 ByteReader r(bytes);
 try{
 uint64_t v=ReadVarU64(r);
 os << "value=" << v << " bytes=" << r.offset();
 if(!r.empty()) os << " trailing=" << r.remaining();
 }
catch(const std::exception& e){
 os << "invalid: " << e.what();
 }
 return os.str();
 }
}
