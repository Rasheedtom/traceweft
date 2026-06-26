
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "traceweft/codec.hpp"
#include "traceweft/record.hpp"
namespace traceweft {
struct FrameHeader {
 uint32_t magic=0;
 uint16_t version=1;
 uint16_t flags=0;
 uint64_t schemaOffset=0;
 uint64_t segmentTableOffset=0;
 uint64_t fileSize=0;
 uint32_t headerCrc=0;
 }
;
struct SegmentInfo {
 uint64_t offset=0;
 uint64_t size=0;
 uint64_t firstTimestamp=0;
 uint64_t lastTimestamp=0;
 uint32_t stream=0;
 PayloadCodec codec=PayloadCodec::Raw;
 uint32_t crc=0;
 }
;
struct Segment {
 SegmentInfo info;
 std::vector<EventRecord> records;
 }
;
FrameHeader ParseFrameHeader(const std::vector<uint8_t>& bytes);
std::vector<uint8_t> SerializeFrameHeader(const FrameHeader& h);
std::vector<SegmentInfo> ParseSegmentTable(const std::vector<uint8_t>& bytes);
std::vector<uint8_t> SerializeSegmentTable(const std::vector<SegmentInfo>& segments);
std::vector<EventRecord> ParseSegmentRecords(const std::vector<uint8_t>& bytes);
std::vector<uint8_t> SerializeSegmentRecords(const std::vector<EventRecord>& records);
std::string DescribeSegment(const SegmentInfo& info);
}
