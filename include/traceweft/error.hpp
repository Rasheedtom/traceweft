
#pragma once
#include <stdexcept>
#include <string>
namespace traceweft {
class Error : public std::runtime_error {
public:
  explicit Error(const std::string& message) : std::runtime_error(message) {
}
}
;
class FormatError : public Error {
 public: explicit FormatError(const std::string& m) : Error(m) {
}
 }
;
class IoError : public Error {
 public: explicit IoError(const std::string& m) : Error(m) {
}
 }
;
class QueryError : public Error {
 public: explicit QueryError(const std::string& m) : Error(m) {
}
 }
;
}
