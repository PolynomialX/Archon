#include <iostream>
#include "window_tools/WindowManager.h"
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
    const auto& exampleWindow = windowManager.getWindow(windowTitle);
    if(exampleWindow.isValid())
    {
        std::cout << "Hurray valid window!" << std::endl;
    }
    else
    {
        std::cout << "Invalid window! Oh dear!" << std::endl;
    }
    // We need threading to handle multiple windows at once but the code is here.
    // We will focus on just rendering to a singular window for the time being.
    // while(!glfwWindowShouldClose(windowManager.getWindow("example_0").getWindow()))
    // {
    //     glfwSwapBuffers(windowManager.getWindow("example_0").getWindow());
    //     glfwPollEvents();
    // }
    return 0;
}
