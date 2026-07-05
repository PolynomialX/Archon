// Have to include glad prior to GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window_tools/WindowManager.h"

namespace archon
{

WindowManager::WindowManager()
{
    std::cout << "Creating an instance of WindowManager\n";
    // Instantiate a GLFW window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


WindowManager::~WindowManager()
{
    std::cout << "Destructing an instance of WindowManager\n";
}


void WindowManager::createWindow(const std::string& title_,
                    int width_,
                    int height_)
{
    // Add to vector & map
    windows.push_back(Window(width_, height_, title_));
    const std::size_t windowIdx = windows.size() - 1;
    windowMap[title_] = windowIdx;
    if(windows[windowIdx].getWindow() == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    // The order of this is important - must change context
    glfwMakeContextCurrent(windows[windowIdx].getWindow());
    // Then init glad
    bool gladInitSuccess = initGLAD();
    if(!gladInitSuccess)
    {
        throw std::runtime_error("Failed to initialise GLAD");
    }
    // then we can call opengl functions
    glViewport(0, 0, windows[windowIdx].getWidth(), windows[windowIdx].getHeight());
    // Set callback function
    glfwSetFramebufferSizeCallback(windows[windowIdx].getWindow(), framebuffer_size_callback);
}

void WindowManager::setWindowContext(const std::string& title_)
{
    auto search = windowMap.find(title_);
    if(search == windowMap.end())
    {
        throw std::runtime_error("ERROR::WINDOW_MANAGER::SET_WINDOW_CONTEXT::"
                                 " CANNOT FIND WINDOW WITH TITLE: " + title_);
    }
    const std::size_t windowIdx = search->second;
    glfwMakeContextCurrent(windows[windowIdx].getWindow());
    glViewport(0, 0, windows[windowIdx].getWidth(), windows[windowIdx].getHeight());
}

Window& WindowManager::getWindow(const std::string& title_)
{
    auto search = windowMap.find(title_);
    if(search == windowMap.end())
    {
        // Cannot find window - raise exception
        throw std::runtime_error("ARCHON::WINDOW_MANAGER::GET_WINDOW"
                                "::ERROR CANNOT FIND WINDOW WITH"
                                "TITLE " + title_);
    }
    return windows[search->second];
}

bool WindowManager::initGLAD()
{
    bool success = true;
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to init GLAD" << std::endl;
        success = false;
    }

    return success;
}

void WindowManager::framebuffer_size_callback(GLFWwindow* window,
        int width,
        int height)
{
    glViewport(0, 0, width, height);
}
} // archon