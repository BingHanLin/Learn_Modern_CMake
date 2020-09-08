# Set the project name
project (staticLibrary)

add_library(${PROJECT_NAME} src/sublib1.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
