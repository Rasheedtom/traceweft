
#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
namespace traceweft {
class ByteReader {
public:
  ByteReader();
  explicit ByteReader(const std::vector<uint8_t>& data);
  ByteReader(const uint8_t* data, size_t size);
  bool empty() const;
  size_t remaining() const;
  size_t offset() const;
  void seek(size_t pos);
  bool canRead(size_t n) const;
  uint8_t readU8();
  uint16_t readU16();
  uint32_t readU32();
  uint64_t readU64();
  int64_t readI64();
  std::vector<uint8_t> readBytes(size_t n);
  std::string readString(size_t n);
  const uint8_t* currentData() const;
private:
  const uint8_t* data_;
  size_t size_;
  size_t off_;
}
;
class ByteWriter {
public:
  void writeU8(uint8_t v);
  void writeU16(uint16_t v);
  void writeU32(uint32_t v);
  void writeU64(uint64_t v);
  void writeI64(int64_t v);
  void writeBytes(const std::vector<uint8_t>& bytes);
  void writeString(const std::string& text);
  const std::vector<uint8_t>& bytes() const;
  std::vector<uint8_t> take();
private:
  std::vector<uint8_t> out_;
}
;
}
