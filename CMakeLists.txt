cmake_minimum_required(VERSION 3.23)
project(archon)
set(CMAKE_CXX_STANDARD 20)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)

add_library(${PROJECT_NAME})
#add_executable(Archon)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
        src/window_tools/WindowManager.cpp
        src/window_tools/Window.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    include)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
            glfw
            opengl::opengl
            glad::glad)

install(TARGETS ${PROJECT_NAME})
