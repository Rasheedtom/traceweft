#include "traceweft/catalog.hpp"
#include "traceweft/stats.hpp"
#include "traceweft/timeline.hpp"
#include <cassert>
using namespace traceweft;
int main(){
  std::vector<EventRecord> records;
  for(int i=0;i<5;i++){ EventRecord r; r.timestamp=100+i; r.stream=1; r.level=i%3; r.service="worker"; r.name="batch.completed"; records.push_back(r); }
  auto st=ComputeStats(records);
  assert(st.records==5);
  assert(st.byService["worker"]==5);
  auto buckets=BuildTimeline(records,2);
  assert(!buckets.empty());
  assert(!BuiltinCatalog().empty());
  assert(ClassifyRecord(records[0])!="");
}
