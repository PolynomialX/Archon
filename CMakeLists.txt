cmake_minimum_required(VERSION 3.23)
project(archon)
set(CMAKE_CXX_STANDARD 20)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(quill REQUIRED)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
  PRIVATE
    src/window_tools/GLWindow.cpp
    src/window_tools/GLWindowFactory.cpp
    src/rendering/RenderOrchestrator.cpp
    src/general/logging/QuillLogger.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/rendering/RenderOrchestrator.h
      include/window_tools/GLWindowFactory.h
      include/window_tools/Window.h
      include/window_tools/WindowFactory.h
      include/window_tools/GLWindow.h
      include/general/logging/ILogger.h
      include/general/logging/QuillLogger.h
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
    include)
# Explicit dependencies
target_link_libraries(${PROJECT_NAME}
        PRIVATE
            glfw
            opengl::opengl
            glad::glad
            quill::quill)
# Custom install command
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    FILE_SET HEADERS DESTINATION include
)
