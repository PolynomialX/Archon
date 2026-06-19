#ifndef ARCHON_WINDOW_MANAGER_H
#define ARCHON_WINDOW_MANAGER_H

// Have to include glad prior to GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// Temp until we add log
#include <iostream>
#include <vector>
#include <exception>
#include <unordered_map>
#include "Window.h"
namespace archon
{

    /**
     * @class WindowManager
     *  Aims to orchestrate the creation and destruction of windows.
     */
class WindowManager
{
public:
    WindowManager();
    virtual ~WindowManager();

    /**
     * @brief getWindow
     *  Currently returns a reference to a desired window
     * @param title_ - title of desired window
     */
    Window& getWindow(const std::string& title_);
private:

    bool initGLAD();

    // Just one window currently
    GLFWwindow* window;

    // Framebuffer size callback - to be moved?
    static void framebuffer_size_callback(GLFWwindow* window,
            int width,
            int height);
    
    std::vector<Window> windows;
    std::unordered_map<std::string, std::size_t> windowMap;
};

} // archon
#endif // ARCHON_WINDOW_MANAGER_H