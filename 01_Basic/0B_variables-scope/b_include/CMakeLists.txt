cmake_minimum_required(VERSION 3.18.0)

project(variables-scope)

set(FOO_A "FOO_A main")


message("FOO_A in main >> ${FOO_A}")

include(child/CMakeLists.txt)

message("FOO_A in main after include >> ${FOO_A}")


