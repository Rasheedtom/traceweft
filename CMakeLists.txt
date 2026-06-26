cmake_minimum_required(VERSION 3.16)
project(traceweft VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB TRACEWEFT_SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(traceweft STATIC ${TRACEWEFT_SOURCES})
target_include_directories(traceweft PUBLIC include)

add_executable(twft tools/twft.cpp)
target_link_libraries(twft PRIVATE traceweft)

include(CTest)
if(BUILD_TESTING)
  add_executable(test_roundtrip tests/test_roundtrip.cpp)
  target_link_libraries(test_roundtrip PRIVATE traceweft)
  add_test(NAME test_roundtrip COMMAND test_roundtrip)

  add_executable(test_query tests/test_query.cpp)
  target_link_libraries(test_query PRIVATE traceweft)
  add_test(NAME test_query COMMAND test_query)

  add_executable(test_schema tests/test_schema.cpp)
  target_link_libraries(test_schema PRIVATE traceweft)
  add_test(NAME test_schema COMMAND test_schema)

  add_executable(test_stats tests/test_stats.cpp)
  target_link_libraries(test_stats PRIVATE traceweft)
  add_test(NAME test_stats COMMAND test_stats)
endif()
