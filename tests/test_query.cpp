#include "traceweft/query.hpp"
#include <cassert>
using namespace traceweft;
int main(){
  EventRecord r; r.timestamp=99; r.stream=3; r.level=4; r.service="worker"; r.name="batch.failed"; r.attributes.push_back({"host","a"});
  auto q=ParseQuery("service = \"worker\" and level >= 4 limit 2");
  assert(MatchesQuery(r,q));
  auto q2=ParseQuery("attr.host = \"b\"");
  assert(!MatchesQuery(r,q2));
}
