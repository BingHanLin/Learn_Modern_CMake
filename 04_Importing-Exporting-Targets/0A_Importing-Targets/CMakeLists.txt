# https://cmake.org/cmake/help/git-stage/guide/importing-exporting/index.html#id5
# https://stackoverflow.com/questions/25907478/possible-to-add-an-imported-library-to-target-link-libraries-that-takes-care-of
cmake_minimum_required(VERSION 3.18.0)

project(importingTargets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_library(foo STATIC IMPORTED)
set_target_properties( foo 
    PROPERTIES
        IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/message/lib/message.lib"
        INTERFACE_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/message/include"
)

add_executable(myApp "${PROJECT_SOURCE_DIR}/src/main.cpp")
target_link_libraries(myApp PRIVATE foo)