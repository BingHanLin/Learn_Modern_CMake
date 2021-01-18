cmake_minimum_required(VERSION 3.18.0)

project(useMathLib)

set(math_DIR ${math_DIR} CACHE STRING "The path to use for math lib" FORCE)
message(STATUS　"math_DIR: ${math_DIR}")

find_package(math REQUIRED COMPONENTS add multiply)
# find_package(math REQUIRED COMPONENTS add multiply substract) not support component

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
    math::add
    math::multiply
)
