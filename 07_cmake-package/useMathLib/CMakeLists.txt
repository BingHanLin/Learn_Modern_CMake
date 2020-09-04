cmake_minimum_required(VERSION 3.15.0)

project(useMathLib)

set(mathLib_DIR ${mathLib_DIR} CACHE STRING "The path to use for math lib" FORCE)

find_package(mathLib)
message("mathLib_DIR: ${mathLib_DIR}")
message("mathLib_LIBRARIES: ${mathLib_LIBRARIES}")
message("mathLib_INCLUDE_DIRS: ${mathLib_INCLUDE_DIRS}")
message("mathLib_FOUND: ${mathLib_FOUND}")



add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} math)
