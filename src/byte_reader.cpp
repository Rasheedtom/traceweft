
#include "traceweft/byte_reader.hpp"
#include "traceweft/error.hpp"
#include <algorithm>
#include <cstring>
namespace traceweft {
ByteReader::ByteReader() : data_(nullptr), size_(0), off_(0) {
}
ByteReader::ByteReader(const std::vector<uint8_t>& data) : data_(data.data()), size_(data.size()), off_(0) {
}
ByteReader::ByteReader(const uint8_t* data, size_t size) : data_(data), size_(size), off_(0) {
}
bool ByteReader::empty() const {
 return off_ >= size_;
 }
size_t ByteReader::remaining() const {
 return off_ > size_ ? 0 : size_ - off_;
 }
size_t ByteReader::offset() const {
 return off_;
 }
void ByteReader::seek(size_t pos) {
 if (pos > size_) throw FormatError("seek beyond input");
 off_ = pos;
 }
bool ByteReader::canRead(size_t n) const {
 return n <= remaining();
 }
const uint8_t* ByteReader::currentData() const {
 return data_ + off_;
 }
uint8_t ByteReader::readU8(){
 if(!canRead(1)) throw FormatError("unexpected end while reading u8");
 return data_[off_++];
 }
uint16_t ByteReader::readU16(){
 if(!canRead(2)) throw FormatError("unexpected end while reading u16");
 uint16_t v=uint16_t(data_[off_]) | (uint16_t(data_[off_+1])<<8);
 off_+=2;
 return v;
 }
uint32_t ByteReader::readU32(){
 if(!canRead(4)) throw FormatError("unexpected end while reading u32");
 uint32_t v=0;
 for(int i=0;i<4;i++) v|=uint32_t(data_[off_+i])<<(8*i);
 off_+=4;
 return v;
 }
uint64_t ByteReader::readU64(){
 if(!canRead(8)) throw FormatError("unexpected end while reading u64");
 uint64_t v=0;
 for(int i=0;i<8;i++) v|=uint64_t(data_[off_+i])<<(8*i);
 off_+=8;
 return v;
 }
int64_t ByteReader::readI64(){
 return static_cast<int64_t>(readU64());
 }
std::vector<uint8_t> ByteReader::readBytes(size_t n){
 if(!canRead(n)) throw FormatError("unexpected end while reading bytes");
 std::vector<uint8_t> b(data_+off_, data_+off_+n);
 off_+=n;
 return b;
 }
std::string ByteReader::readString(size_t n){
 auto b=readBytes(n);
 return std::string(b.begin(), b.end());
 }
void ByteWriter::writeU8(uint8_t v){
 out_.push_back(v);
 }
void ByteWriter::writeU16(uint16_t v){
 out_.push_back(uint8_t(v));
 out_.push_back(uint8_t(v>>8));
 }
void ByteWriter::writeU32(uint32_t v){
 for(int i=0;i<4;i++) out_.push_back(uint8_t(v>>(8*i)));
 }
void ByteWriter::writeU64(uint64_t v){
 for(int i=0;i<8;i++) out_.push_back(uint8_t(v>>(8*i)));
 }
void ByteWriter::writeI64(int64_t v){
 writeU64(static_cast<uint64_t>(v));
 }
void ByteWriter::writeBytes(const std::vector<uint8_t>& bytes){
 out_.insert(out_.end(), bytes.begin(), bytes.end());
 }
void ByteWriter::writeString(const std::string& text){
 out_.insert(out_.end(), text.begin(), text.end());
 }
const std::vector<uint8_t>& ByteWriter::bytes() const {
 return out_;
 }
std::vector<uint8_t> ByteWriter::take(){
 return std::move(out_);
 }
}
