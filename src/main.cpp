#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <thread>
#include <chrono>

#include "WindowManager.h"

int main()
{
    std::cout << "Hello Archon" << std::endl;
    archon::WindowManager windowManager;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    auto& greeblesWindow = windowManager.getWindow("Greebles");
    greeblesWindow.setHeight(1000);
    greeblesWindow.setWidth(500);
    while(!glfwWindowShouldClose(greeblesWindow.getWindow()))
    {
        glfwSwapBuffers(greeblesWindow.getWindow());
        glfwPollEvents();
    }
    return 0;
}