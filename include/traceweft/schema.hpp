
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "traceweft/byte_reader.hpp"
namespace traceweft {
struct FieldDef {
 std::string name;
 std::string type;
 bool optional=false;
 uint32_t id=0;
 }
;
struct StreamDef {
 uint32_t id=0;
 std::string name;
 std::string service;
 std::vector<FieldDef> fields;
 }
;
struct Schema {
 uint32_t version=1;
 std::vector<StreamDef> streams;
 }
;
Schema ParseSchemaText(const std::string& text);
std::string FormatSchemaText(const Schema& schema);
Schema ParseSchemaBlock(const std::vector<uint8_t>& bytes);
std::vector<uint8_t> SerializeSchemaBlock(const Schema& schema);
const StreamDef* FindStream(const Schema& schema, uint32_t id);
std::vector<std::string> ValidateSchema(const Schema& schema);
}
