cmake_minimum_required(VERSION 3.18.0)

project(set-variables)

set(MY_CACHE_VAR "I am a cached variable" CACHE STRING "Description")

message(STATUS "MY_CACHE_VAR ${MY_CACHE_VAR}")
