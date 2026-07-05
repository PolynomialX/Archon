#include <iostream>
#include "window_tools/WindowManager.h"
int main()
{
    std::cout << "Hello from example_0" << std::endl;
    archon::WindowManager windowManager;
    windowManager.createWindow("example_0", 1000, 1000);

    // We need threading to handle multiple windows at once but the code is here.
    // We will focus on just rendering to a singular window for the time being.
    while(!glfwWindowShouldClose(windowManager.getWindow("example_0").getWindow()))
    {
        glfwSwapBuffers(windowManager.getWindow("example_0").getWindow());
        glfwPollEvents();
    }
    return 0;
}
