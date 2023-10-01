cmake_minimum_required (VERSION 3.18)

project("zeroMQTestTask" VERSION 2.0)

set(CMAKE_CXX_SANDARD 11)

  set(PROTO_PATH "${CMAKE_CURRENT_SOURCE_DIR}/proto_definitions")

file(GLOB PROTO_FILES "${CURRENT_SOURCE_DIR}/*.proto")

foreach(PROTO_FILE in ${PROTO_FILES})

    string(REGEX REPLACE "[.]proto$" ".pb.cc" OUTPUT_SOURCE ${PROTO_FILE})
    list(APPEND OUTPUT_SOURCES ${OUTPUT_SOURCE}) 

endforeach()

add_library(zeroMQTestTask {CURRENT_SOURCE_DIR})

add_executable(zeroMQTestTask main.cpp)

target_include_directories(${zeroMQTestTask} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
