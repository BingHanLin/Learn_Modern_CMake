# https://cmake.org/cmake/help/git-stage/guide/importing-exporting/index.html#id5

cmake_minimum_required(VERSION 3.18.0)

project(messageLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_library(msg
  STATIC
    "${PROJECT_SOURCE_DIR}/src/message.cpp"
)

target_include_directories(msg
    PUBLIC
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"
)

install(TARGETS msg
    EXPORT msgTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# why i need to install header file manually?
install(FILES "${PROJECT_SOURCE_DIR}/include/message.hpp" 
    DESTINATION include
)

install(EXPORT msgTargets
    FILE msgTargets.cmake
    NAMESPACE message::
    DESTINATION lib/cmake
)
