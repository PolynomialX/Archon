#include <iostream>
#include "window_tools/WindowManager.h"
#include "rendering/RenderOrchestrator.h"
int main()
{
    std::cout << "Hello from example_0" << std::endl;
    const std::string windowTitle = "example_0";
    constexpr int width = 500;
    constexpr int height = 1000;
    archon::WindowManager windowManager;
    windowManager.createWindow(windowTitle, width, height);
    // From this I think createWindow should return a reference to the newly created window.
    // I also think the WindowManager should store unique pointers to windows to express ownership
    auto& exampleWindow = windowManager.getWindow(windowTitle);
    if(exampleWindow.isValid())
    {
        std::cout << "Hurray valid window!" << std::endl;
    }
    else
    {
        std::cout << "Invalid window! Oh dear!" << std::endl;
    }
    
   archon::RenderOrchestrator::simpleRenderLoop(exampleWindow);
   
    return 0;
}
