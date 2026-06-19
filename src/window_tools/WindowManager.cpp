#include "WindowManager.h"

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
    windows.push_back(Window(800, 600, "Greebles"));
    windowMap["Greebles"] = 0;
    if(windows[0].getWindow() == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    // Needed before initing GLAD
    glfwMakeContextCurrent(windows[0].getWindow());
    bool gladInitSuccess = initGLAD();
    if(!gladInitSuccess)
    {
        throw std::runtime_error("Failed to initialise GLAD");
    }

    // Tell OpenGL the size of the rendering window
    glViewport(0,
         0,
         800, 
         600);

    glfwSetFramebufferSizeCallback(windows[0].getWindow(), framebuffer_size_callback);
    

}


WindowManager::~WindowManager()
{
    std::cout << "Destructing an instance of WindowManager\n";
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