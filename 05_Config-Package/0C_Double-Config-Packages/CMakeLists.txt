# https://cmake.org/cmake/help/git-stage/guide/importing-exporting/index.html#id5

cmake_minimum_required(VERSION 3.18.0)

project(importingLibraries)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

set(msg_DIR "${PROJECT_SOURCE_DIR}/message/install/lib/cmake")
find_package(msg)

add_executable(myApp "${PROJECT_SOURCE_DIR}/src/main.cpp")
target_link_libraries(myApp PRIVATE message::msg)
