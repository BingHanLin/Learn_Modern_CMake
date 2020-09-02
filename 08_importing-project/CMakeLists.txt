cmake_minimum_required(VERSION 3.15.0)

project(importing-project VERSION 1.2.3)

find_package(mathLib PATHS install/cmake/mathLibCmake)

message("Found >> ${mathLib}")