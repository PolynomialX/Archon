#ifndef ARCHON_WINDOW_MANAGER_H
#define ARCHON_WINDOW_MANAGER_H

// Have to include glad prior to GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// Temp until we add log
#include <iostream>
#include <vector>
#include <exception>
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

private:

    bool initGLAD();

    // Just one window currently
    GLFWwindow* window;

    // Framebuffer size callback - to be moved?
    static void framebuffer_size_callback(GLFWwindow* window,
            int width,
            int height);
    
    std::vector<Window> windows;
};

} // archon
#endif // ARCHON_WINDOW_MANAGER_H