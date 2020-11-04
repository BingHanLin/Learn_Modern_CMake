cmake_minimum_required(VERSION 3.18.0)

project(dependencies-conflicting)

add_library(lib1 STATIC lib1.cpp)
target_include_directories(lib1 INTERFACE ${PROJECT_SOURCE_DIR})
set_property(TARGET lib1 PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE   ON)

add_executable(main main.cpp)
target_link_libraries(main lib1)
set_property(TARGET main PROPERTY POSITION_INDEPENDENT_CODE  OFF)

