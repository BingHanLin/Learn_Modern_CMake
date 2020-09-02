cmake_minimum_required(VERSION 3.15.0)

project(importing-project VERSION 1.2.3)

if( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
    message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/install")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "The path to use for make install" FORCE)
endif()

add_library(mathLib 
    STATIC
    ${PROJECT_SOURCE_DIR}/mathLib/mathLib.cpp
    ${PROJECT_SOURCE_DIR}/mathLib/mathLib.hpp
)


set(versionConfig ${PROJECT_SOURCE_DIR}/mathLibConfigVersion.cmake)
set(projectConfig ${PROJECT_SOURCE_DIR}/mathLibConfig.cmake)

include(CMakePackageConfigHelpers)
configure_package_config_file( 
    ${PROJECT_SOURCE_DIR}/Config.cmake.in
    projectConfig
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyPack
    PATH_VARS
    CMAKE_INSTALL_LIBDIR
)
write_basic_package_version_file(
    versionConfig
    COMPATIBILITY SameMajorVersion
)

### Install Config and ConfigVersion files

install( 
    TARGET mathLib
    EXPORT mathLibTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)

install(
  EXPORT mathLibTargets
  DESTINATION lib/cmake/MyPack
  NAMESPACE MyPack::
  FILE mathLibTargets.cmake
)
