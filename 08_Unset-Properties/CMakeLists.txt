cmake_minimum_required(VERSION 3.18.0)

project(unsetProperties)

# collect all cmake properies
if(NOT COLLECTED_CMAKE_PROPERTY_LIST)
    execute_process(COMMAND cmake --help-property-list OUTPUT_VARIABLE COLLECTED_CMAKE_PROPERTY_LIST)
    
    # Convert command output into a CMake list
    string(REGEX REPLACE ";" "\\\\;" COLLECTED_CMAKE_PROPERTY_LIST "${COLLECTED_CMAKE_PROPERTY_LIST}")
    string(REGEX REPLACE "\n" ";" COLLECTED_CMAKE_PROPERTY_LIST "${COLLECTED_CMAKE_PROPERTY_LIST}")
endif()

# unset all cmake properies
foreach(ONE_PROPERTY ${COLLECTED_CMAKE_PROPERTY_LIST})
    string(REPLACE "<CONFIG>" "${CMAKE_BUILD_TYPE}" ONE_PROPERTY ${ONE_PROPERTY})

    # Fix https://stackoverflow.com/questions/32197663/how-can-i-remove-the-the-location-property-may-not-be-read-from-target-error-i
    if(ONE_PROPERTY STREQUAL "LOCATION" OR ONE_PROPERTY MATCHES "^LOCATION_" OR ONE_PROPERTY MATCHES "_LOCATION$")
        continue()
    endif()

    set_property(SOURCE main.cpp PROPERTY ${ONE_PROPERTY})
endforeach()
