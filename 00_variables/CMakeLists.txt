cmake_minimum_required(VERSION 3.15.0)

project(variables)

set(FOO "x")
set(MY_CACHE_STRING "value" CACHE STRING "a cache string variable" FORCE)
set(MY_CACHE_PATH "path" CACHE PATH "a  cache  path variable" FORCE)
set(MY_CACHE_BOOL "ON" CACHE BOOL "a  cache  path bool" FORCE)

