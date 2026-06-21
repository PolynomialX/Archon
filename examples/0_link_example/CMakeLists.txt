cmake_minimum_required(VERSION 3.23)
project(example_0)
set(CMAKE_CXX_STANDARD 20)
find_package(archon REQUIRED)

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    archon::archon)

target_sources(${PROJECT_NAME}
    PRIVATE 
        src/main.cpp
    )