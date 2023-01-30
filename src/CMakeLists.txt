cmake_minimum_required(VERSION 3.18.X)

SET(MY_VAR_DIR ${CMAKE_SOURCE_DIR}/headers)

add_executable(zeroMQTest mainFile.cpp ${MY_VAR_DIR}/server.h ${MY_VAR_DIR}/client.h server.cpp client.cpp)
target_include_directories(zeroMQTest PUBLIC ${MY_VAR_DIR})
