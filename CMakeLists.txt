cmake_minimum_required(VERSION 3.23)
project(archon)
set(CMAKE_CXX_STANDARD 20)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
  PRIVATE
    src/window_tools/WindowManager.cpp
    src/window_tools/Window.cpp

    src/rendering/RenderOrchestrator.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/rendering/RenderOrchestrator.h
      include/window_tools/Window.h
      include/window_tools/WindowManager.h
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
    include)
# Explicit dependencies
target_link_libraries(${PROJECT_NAME}
        PRIVATE
            glfw
            opengl::opengl
            glad::glad)
# Custom install command
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    FILE_SET HEADERS DESTINATION include
)
