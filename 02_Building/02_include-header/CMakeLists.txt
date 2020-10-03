cmake_minimum_required(VERSION 3.15.0)

project(include-header)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(SOURCE_FILE
  ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILE})

target_include_directories(${CMAKE_PROJECT_NAME} 
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)