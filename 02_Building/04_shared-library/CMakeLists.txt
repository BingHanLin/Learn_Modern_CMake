cmake_minimum_required(VERSION 3.15.0)

project(shared-library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

if (WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif()

add_library(message
  SHARED
    ${PROJECT_SOURCE_DIR}/messageLib/message.cpp
)

target_include_directories(message 
  PUBLIC
    ${PROJECT_SOURCE_DIR}/messageLib
)

set(SOURCE_FILE ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILE})

target_link_libraries(${CMAKE_PROJECT_NAME} message)
