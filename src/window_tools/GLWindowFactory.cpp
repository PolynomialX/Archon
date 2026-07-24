#include "window_tools/GLWindowFactory.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace archon
{
namespace window_tools
{
namespace archon_gl
{
GLWindowFactory::GLWindowFactory()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLWindowFactory::~GLWindowFactory()
{
    glfwTerminate();
}

std::unique_ptr<WindowBase> GLWindowFactory::createWindow(int width_,
                                                          int height_,
                                                          const std::string& title_)
{
    return std::make_unique<GLWindow>(width_, height_, title_);
}
} // archon_gl
} // window_tools
} // archon