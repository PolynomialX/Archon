#include <iostream>
#include "window_tools/GLWindowFactory.h"
#include "rendering/RenderOrchestrator.h"
int main()
{
    std::cout << "Hello from example_0_1, updated software design!" << std::endl;
    const std::string windowTitle = "example_0_1";
    constexpr int width = 500;
    constexpr int height = 1000;
    archon::window_tools::archon_gl::GLWindowFactory glWindowFactory;
    auto window = glWindowFactory.createWindow(width, height, windowTitle);
    
   archon::RenderOrchestrator::simpleRenderLoop(*window);
   
    return 0;
}
