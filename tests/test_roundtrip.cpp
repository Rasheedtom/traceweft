#include "traceweft/trace_file.hpp"
#include <cassert>
#include <iostream>
using namespace traceweft;
int main(){
  Schema s;
  StreamDef st;
  st.id=7; st.name="jobs"; st.service="worker";
  st.fields.push_back({"job","string",false,1});
  s.streams.push_back(st);
  EventRecord r;
  r.timestamp=10; r.stream=7; r.level=2; r.service="worker"; r.name="batch.completed";
  r.attributes.push_back({"job","nightly"});
  Segment seg; seg.info.codec=PayloadCodec::Raw; seg.records.push_back(r);
  auto bytes=WriteTraceBytes(s,{seg});
  auto tf=ReadTraceBytes(bytes);
  assert(tf.schema.streams.size()==1);
  auto records=FlattenRecords(tf);
  assert(records.size()==1);
  assert(records[0].service=="worker");
  std::cout<<InspectTrace(tf);
}
