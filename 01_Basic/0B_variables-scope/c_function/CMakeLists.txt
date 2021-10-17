cmake_minimum_required(VERSION 3.18.0)

project(variables-scope)

set(FOO_A "FOO_A main")
set(FOO_B "FOO_B main")

message("FOO_A in main >> ${FOO_A}")
message("FOO_B in main >> ${FOO_B}")

function(funcA param)
    set(${param} "FOO_A function")
endfunction()

function(funcB param)
    set(${param} "FOO_B function" PARENT_SCOPE)
endfunction()

funcA(FOO_A)
funcB(FOO_B)


message("FOO_A in main after function >> ${FOO_A}")
message("FOO_B in main after function >> ${FOO_B}")





