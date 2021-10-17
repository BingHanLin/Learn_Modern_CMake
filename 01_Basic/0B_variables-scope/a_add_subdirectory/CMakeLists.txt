cmake_minimum_required(VERSION 3.18.0)

project(variables-scope)

set(FOO_A "FOO_A main")
set(FOO_B "FOO_B main")


message("FOO_A in main >> ${FOO_A}")
message("FOO_B in main >> ${FOO_B}")

add_subdirectory(child)

message("FOO_A in main after add_subdirectory >> ${FOO_A}")
message("FOO_B in main after add_subdirectory >> ${FOO_B}")



