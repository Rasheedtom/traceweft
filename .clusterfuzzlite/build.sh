#!/bin/bash -eu
CXX=${CXX:-clang++}
mkdir -p "$OUT"
common_sources="byte_reader.cpp crc32.cpp varint.cpp record.cpp codec.cpp frame.cpp schema.cpp trace_file.cpp query.cpp"
objs=""
for name in $common_sources; do
  src="$SRC/src/$name"
  obj="$OUT/${name%.cpp}.o"
  $CXX $CXXFLAGS -std=c++17 -I"$SRC/include" -c "$src" -o "$obj"
  objs="$objs $obj"
done
for fuzzer in trace_reader_fuzzer frame_fuzzer query_fuzzer schema_fuzzer codec_fuzzer; do
  $CXX $CXXFLAGS -std=c++17 -I"$SRC/include" "$SRC/fuzz/${fuzzer}.cc" $objs $LIB_FUZZING_ENGINE -o "$OUT/$fuzzer"
done
