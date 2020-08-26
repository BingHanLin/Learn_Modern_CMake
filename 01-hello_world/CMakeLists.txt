cmake_minimum_required(VERSION 3.15.0)

project(hello-world)

set(SOURCE_FILES main.cpp)

message(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})