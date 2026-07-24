#include "rendering/RenderOrchestrator.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace archon
{

void RenderOrchestrator::simpleRenderLoop(window_tools::WindowBase& windowToRenderTo_)
{
    while(!windowToRenderTo_.shouldClose())
    {
        windowToRenderTo_.swapBuffers();
        // This needs to be generic but will do for now
        glfwPollEvents();
    }
}

}