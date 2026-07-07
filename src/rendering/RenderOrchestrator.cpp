#include "rendering/RenderOrchestrator.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace archon
{

void RenderOrchestrator::simpleRenderLoop(Window& windowToRenderTo_)
{
    while(!windowToRenderTo_.shouldClose())
    {
        windowToRenderTo_.swapBuffers();
        glfwPollEvents();
    }
}

}