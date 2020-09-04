cmake_minimum_required(VERSION 3.15.0)

project(mathLib VERSION 1.2.3)

if( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
    message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${PROJECT_SOURCE_DIR}/install")
    set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install" CACHE STRING "The path to use for make install" FORCE)
endif()

set(INSTALL_INCLUDES_DIR include)
set(INSTALL_LIB_DIR lib)
set(INSTALL_BIN_DIR src)

add_library(math
    STATIC
        ${PROJECT_SOURCE_DIR}/src/math.cpp
)

target_include_directories(math 
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${INSTALL_INCLUDES_DIR}>
)

###############################
# Configuration
###############################
set(projectConfig ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake)
set(versionConfig ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake)

# include module
include(CMakePackageConfigHelpers)
# write version config
write_basic_package_version_file(
    ${versionConfig}
    COMPATIBILITY SameMajorVersion
)
# write porject config
configure_package_config_file( 
    ${PROJECT_SOURCE_DIR}/cmake/Config.cmake.in
    ${projectConfig}
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)


###############################
# Install
###############################
install( 
    TARGETS math
    EXPORT ${PROJECT_NAME}Target
    LIBRARY DESTINATION ${INSTALL_LIB_DIR}
    ARCHIVE DESTINATION ${INSTALL_LIB_DIR}
    RUNTIME DESTINATION ${INSTALL_BIN_DIR}
	# INCLUDES DESTINATION ${INSTALL_INCLUDES_DIR}
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${INSTALL_INCLUDES_DIR}
    FILES_MATCHING PATTERN "*.hpp"
)

# install target
install(
    EXPORT 
        ${PROJECT_NAME}Target
    DESTINATION
        lib/cmake/
)

# install version config and porject config files
install(
    FILES
        ${projectConfig} ${versionConfig}
    DESTINATION
        lib/cmake/
)
