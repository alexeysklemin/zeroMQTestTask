cmake_minimum_required (VERSION 3.18)

project("zeroMQTestTask" VERSION 2.0)

set(CMAKE_CXX_SANDARD 11)

find_package(Protobuf REQUIERD)

set(Protobuf_IMPORT_DIRS "${CMAKE_CURRENT_SOURCE_DIR/proto_schemas/}")

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS  service.proto)

add_library(proto ${PROTO_SRC} ${PROTO_HDRS})

add_executable(zeroMQTestTask main.cpp)

target_link_libraries(zeroMQTestTask PRIVATE ${PROTOBUF__LIBRARIES})
