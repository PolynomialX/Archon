cmake_minimum_required(VERSION 3.23)
project(archon)
set(CMAKE_CXX_STANDARD 20)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
  PRIVATE
    src/window_tools/GLWindow.cpp
    src/window_tools/GLWindowFactory.cpp
    src/rendering/RenderOrchestrator.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/rendering/RenderOrchestrator.h
      include/window_tools/GLWindowFactory.h
      include/window_tools/WindowBase.h
      include/window_tools/WindowFactory.h
      include/window_tools/GLWindow.h
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
