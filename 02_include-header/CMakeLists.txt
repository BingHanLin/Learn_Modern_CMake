cmake_minimum_required(VERSION 3.15.0)

project(include-header)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/src/message.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} 
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)