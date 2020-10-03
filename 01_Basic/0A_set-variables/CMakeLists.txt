cmake_minimum_required(VERSION 3.18.0)

project(set-variables)

set(FOO "x")
set(MY_CACHE_STRING "value" CACHE STRING "a cache string variable" FORCE)
set(MY_CACHE_PATH "path" CACHE PATH "a  cache path variable" FORCE)
set(MY_CACHE_BOOL "ON" CACHE BOOL "a  cache bool variable" FORCE)

message("ENV_path >>  ")
message("$ENV{path}")



