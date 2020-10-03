cmake_minimum_required(VERSION 3.15.0)

project(installing)

if( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
  message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/install")
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "The path to use for make install" FORCE)
endif()

if (WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif()

############################################################
# Create a library
############################################################
add_library(message
  SHARED
    ${PROJECT_SOURCE_DIR}/messageLib/message.cpp
)

target_include_directories(message 
  PUBLIC
    ${PROJECT_SOURCE_DIR}/messageLib
)

############################################################
# Create an executable
############################################################
set(SOURCE_FILE ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILE})

target_link_libraries(${CMAKE_PROJECT_NAME} message)

############################################################
# Install
############################################################
# Binaries
install (TARGETS ${CMAKE_PROJECT_NAME}
    DESTINATION bin)

# Library
install (TARGETS message
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

# Config file
install (FILES ${PROJECT_SOURCE_DIR}/example.conf
    DESTINATION etc)


