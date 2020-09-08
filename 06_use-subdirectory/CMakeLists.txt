cmake_minimum_required(VERSION 3.15.0)

project(subprojects)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Add sub directories
add_subdirectory(headerLibrary)
add_subdirectory(staticLibrary)
add_subdirectory(myApp)
