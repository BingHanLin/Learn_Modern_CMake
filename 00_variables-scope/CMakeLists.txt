cmake_minimum_required(VERSION 3.15.0)

project(variables-scope)

function(FOOFunc f)
    message("Show FOO in main function >> ${f}")
    set(f "foo-In-Main-Function")
    message("Show FOO in main function >> ${f}")
endfunction()

set(FOO "foo-In-Main")
message("Show FOO in main >> ${FOO}")

add_subdirectory(sub)

FOOFunc(${FOO})

message("Show FOO in main >> ${FOO}")


