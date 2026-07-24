// Have to include glad prior to GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <exception>
// Temp until we add log
#include <iostream>
#include "window_tools/WindowManager.h"


namespace archon
{
namespace window_tools
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
    windows.emplace_back(std::make_unique<Window>(width_, height_, title_));
    // Get idx
    const std::size_t windowIdx = windows.size() - 1;
    // Set in map
    windowMap[title_] = windowIdx;
    // Check 
    if(!windows[windowIdx]->isValid())
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    // The order of this is important - must change context
    windows[windowIdx]->makeActive();
    // Then init glad if this is the first window
    if(windowIdx == 0)
    {
        bool gladInitSuccess = initGLAD();
        if(!gladInitSuccess)
        {
            throw std::runtime_error("Failed to initialise GLAD");
        }
    }

    // then we can call opengl functions
    glViewport(0, 
               0, 
               windows[windowIdx]->getWidth(), 
               windows[windowIdx]->getHeight());
    // Set callback function
    windows[windowIdx]->setFramebufferSizeCallback();
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
    windows[windowIdx]->makeActive();
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
    // Is this safe?
    // Think so - needs documenting or having a look at?
    return *windows[search->second].get();
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

} // window_tools
} // archon