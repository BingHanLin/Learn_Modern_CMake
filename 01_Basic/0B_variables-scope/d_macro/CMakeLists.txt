cmake_minimum_required(VERSION 3.18.0)

project(variables-scope)

set(FOO_A "FOO_A main")

message("FOO_A in main >> ${FOO_A}")

macro(mac param)
    set(${param} "FOO_A macro")
endmacro()

mac(FOO_A)

message("FOO_A in main after macro >> ${FOO_A}")

