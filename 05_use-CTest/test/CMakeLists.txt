cmake_minimum_required(VERSION 3.18.0)

project(run-CTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(CATCH_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/test.cpp)

target_include_directories(${CMAKE_PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/catch2
)