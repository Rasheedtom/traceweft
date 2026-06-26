
#pragma once
#include <functional>
#include <string>
#include <vector>
#include "traceweft/record.hpp"
namespace traceweft {
struct QueryPredicate {
 std::string field;
 std::string op;
 std::string value;
 }
;
struct Query {
 std::vector<QueryPredicate> terms;
 bool matchAll=true;
 uint64_t limit=0;
 }
;
Query ParseQuery(const std::string& expr);
bool MatchesQuery(const EventRecord& rec, const Query& q);
std::vector<EventRecord> FilterRecords(const std::vector<EventRecord>& records, const Query& q);
std::string ExplainQuery(const Query& q);
}
