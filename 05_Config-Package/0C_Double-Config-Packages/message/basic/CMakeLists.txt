# https://cmake.org/cmake/help/git-stage/guide/importing-exporting/index.html#id5

cmake_minimum_required(VERSION 3.18.0)

project(basicLib VERSION 1.2.3)

set(CMAKE_CXX_STANDARD 17)

add_library(basic INTERFACE)

target_include_directories(basic
    INTERFACE 
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:include>"
)

###############################
# Configuration
###############################
set(projectConfig ${PROJECT_BINARY_DIR}/basicConfig.cmake)
set(versionConfig ${PROJECT_BINARY_DIR}/basicConfigVersion.cmake)

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
install(TARGETS basic
    EXPORT basicTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# why i need to install header file manually?
install(FILES "${PROJECT_SOURCE_DIR}/basic.hpp" 
    DESTINATION include
)

install(EXPORT basicTargets
    FILE basicTargets.cmake
    NAMESPACE basic::
    DESTINATION lib/cmake
)

# install version config and porject config files
install(
    FILES
        ${projectConfig} ${versionConfig}
    DESTINATION
        lib/cmake/
)