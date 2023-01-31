cmake_minimum_required(VERSION 3.18.X)
project(zeroMQTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lzmq")

file(GLOB SRC_FILES src/*.cpp)
file(GLOB HEADER_FILES headers/*.h)

add_executable(${PROJECT_NAME} mainFile.cpp /headers//server.h /headers/client.h /src/client.cpp /src/server.cpp)

