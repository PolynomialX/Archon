cmake_minimum_required(VERSION 3.23)
project(Archon)

find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)

add_executable(Archon)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
            glfw
            opengl::opengl
            glad::glad)
        
