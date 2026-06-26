#include "traceweft/schema.hpp"
#include <cassert>
using namespace traceweft;
int main(){
  auto schema=ParseSchemaText("version 2\nstream 1 jobs worker\nfield 1 id string\nfield 2 ok bool optional\n");
  auto issues=ValidateSchema(schema);
  assert(issues.empty());
  auto bytes=SerializeSchemaBlock(schema);
  auto again=ParseSchemaBlock(bytes);
  assert(again.version==2);
  assert(FindStream(again,1)!=nullptr);
}
