cmake_minimum_required(VERSION 3.18.0)

project(run-CTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(CATCH_INCLUDE_DIR ${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/src/test.cpp
    ${PROJECT_SOURCE_DIR}/src/sqrTest.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/catch2
        ${PROJECT_SOURCE_DIR}/../include
)

add_test(
    NAME sqrTest 
    COMMAND ${PROJECT_NAME}
)