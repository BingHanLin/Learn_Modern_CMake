project(subbinary)

# Create the executable
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    headerLibrary
    staticLibrary
)
