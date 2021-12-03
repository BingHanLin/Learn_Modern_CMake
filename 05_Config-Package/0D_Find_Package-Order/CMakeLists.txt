cmake_minimum_required(VERSION 3.18.0)

project(find-package-order)

set(PackageName "HDF5")
set(PackageConfigPath "C:/Lib/HDF5-1.12.0-MINGW/cmake/hdf5")

# Print extra find call information
set(CMAKE_FIND_DEBUG_MODE TRUE)

# No.0 
# A cache entry called <PackageName>_DIR is created to hold the directory containing the file.
# It seems this variable is used if it is set.
set(${PackageName}_DIR ${PackageConfigPath})

# No.1 
# Search paths specified in the <PackageName>_ROOT
# Skip by NO_PACKAGE_ROOT_PATH in find_package
set(${PackageName}_ROOT ${PackageConfigPath})
set(CMAKE_FIND_USE_PACKAGE_ROOT_PATH FALSE) # TRUE/FALSE

# No.2 
# Search paths specified in cmake-specific cache variables.
# Skip by NO_CMAKE_PATH in find_package
set(CMAKE_PREFIX_PATH  ${PackageConfigPath})
# set(CMAKE_FRAMEWORK_PATH  ${PackageConfigPath})
# set(CMAKE_FRAMEWORK_PATH  ${PackageConfigPath})
set(CMAKE_FIND_USE_CMAKE_PATH FALSE) # TRUE/FALSE
message(STATUS  "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message(STATUS  "CMAKE_FRAMEWORK_PATH: ${CMAKE_FRAMEWORK_PATH}")
message(STATUS  "CMAKE_APPBUNDLE_PATH: ${CMAKE_APPBUNDLE_PATH}")

# No.3 
# Search paths specified in cmake-specific environment variables.
# Skip by NO_CMAKE_ENVIRONMENT_PATH in find_package
set(ENV{${PackageName}_DIR} ${PackageConfigPath})
# set(ENV{CMAKE_PREFIX_PATH} ${PackageConfigPath})
# set(ENV{CMAKE_FRAMEWORK_PATH} ${PackageConfigPath})
# set(ENV{CMAKE_APPBUNDLE_PATH} ${PackageConfigPath})
set(CMAKE_FIND_USE_CMAKE_ENVIRONMENT_PATH FALSE) # TRUE/FALSE
message(STATUS  "ENV{<PackageName>_DIR}: $ENV{${PackageName}_DIR}")
message(STATUS  "ENV{CMAKE_PREFIX_PATH}: $ENV{CMAKE_PREFIX_PATH}")
message(STATUS  "ENV{CMAKE_FRAMEWORK_PATH}: $ENV{CMAKE_FRAMEWORK_PATH}")
message(STATUS  "ENV{CMAKE_APPBUNDLE_PATH}: $ENV{CMAKE_APPBUNDLE_PATH}")

# No.4 
# Search paths specified by the HINTS option in find_package.

# No.5 
# Search the standard system environment variables.
# Skip by NO_SYSTEM_ENVIRONMENT_PATH in find_package
set(CMAKE_FIND_USE_SYSTEM_ENVIRONMENT_PATH FALSE) # TRUE/FALSE

# No.6 
# Search paths stored in the CMake User Package Registry.
# Skip by NO_CMAKE_PACKAGE_REGISTRY in find_package
set(CMAKE_FIND_USE_PACKAGE_REGISTRY FALSE) # TRUE/FALSE

# No.7 
# Search cmake variables defined in the Platform files for the current system.
# Skip by NO_CMAKE_SYSTEM_PATH in find_package
set(CMAKE_SYSTEM_PREFIX_PATH  ${PackageConfigPath})
# set(CMAKE_SYSTEM_FRAMEWORK_PATH  ${PackageConfigPath})
# set(CMAKE_SYSTEM_APPBUNDLE_PATH  ${PackageConfigPath})
set(CMAKE_FIND_USE_CMAKE_SYSTEM_PATH FALSE) # TRUE/FALSE
message(STATUS  "CMAKE_SYSTEM_PREFIX_PATH: ${CMAKE_SYSTEM_PREFIX_PATH}")
message(STATUS  "CMAKE_SYSTEM_FRAMEWORK_PATH: ${CMAKE_SYSTEM_FRAMEWORK_PATH}")
message(STATUS  "CMAKE_SYSTEM_APPBUNDLE_PATH: ${CMAKE_SYSTEM_APPBUNDLE_PATH}")

# No.8
# Search cmake variables defined in the Platform files for the current system.
# Skip by NO_CMAKE_SYSTEM_PACKAGE_REGISTRY in find_package
set(CMAKE_FIND_USE_SYSTEM_PACKAGE_REGISTRY FALSE) # TRUE/FALSE

# No.9
# Search paths specified by the PATHS option in find_package.

set(HDF5_USE_STATIC_LIBRARIES TRUE)
find_package(HDF5 
    REQUIRED
    CONFIG # Enforce pure Config mode
    # HINTS ${PackageConfigPath}
    # PATHS ${PackageConfigPath}
)