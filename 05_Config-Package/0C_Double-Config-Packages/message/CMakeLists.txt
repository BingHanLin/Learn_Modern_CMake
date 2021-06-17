# https://cmake.org/cmake/help/git-stage/guide/importing-exporting/index.html#id5

cmake_minimum_required(VERSION 3.18.0)

project(messageLib VERSION 1.2.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")


set(basic_DIR "${PROJECT_SOURCE_DIR}/basic/install/lib/cmake")
message(STATUS ${basic_DIR})
find_package(basic REQUIRED)

add_library(msg
  STATIC
    "${PROJECT_SOURCE_DIR}/src/message.cpp"
)

target_include_directories(msg
    PUBLIC
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"
)

target_link_libraries(msg
    PUBLIC basic::basic
)

###############################
# Configuration
###############################
set(projectConfig ${PROJECT_BINARY_DIR}/msgConfig.cmake)
set(versionConfig ${PROJECT_BINARY_DIR}/msgConfigVersion.cmake)

# include module
include(CMakePackageConfigHelpers)
# write version config
write_basic_package_version_file(
    ${versionConfig}
    COMPATIBILITY SameMajorVersion
)
# write porject config
configure_package_config_file( 
    ${PROJECT_SOURCE_DIR}/Config.cmake.in
    ${projectConfig}
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

###############################
# Install
###############################
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

# install version config and porject config files
install(
    FILES
        ${projectConfig} ${versionConfig}
    DESTINATION
        lib/cmake/
)
