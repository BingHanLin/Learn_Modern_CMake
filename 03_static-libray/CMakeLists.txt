cmake_minimum_required(VERSION 3.15.0)

project(static-libray)

add_library(message
  STATIC
    ${PROJECT_SOURCE_DIR}/lib/message.cpp
)

target_include_directories(message 
  PUBLIC
    ${PROJECT_SOURCE_DIR}/lib
)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} message)
