cmake_minimum_required(VERSION 3.23)
project(Archon)

find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)

add_executable(Archon)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
        src/window_tools/WindowManager.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    src
    src/window_tools)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
            glfw
            opengl::opengl
            glad::glad)
        
