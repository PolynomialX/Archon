#include "Window.h"
namespace archon
{

Window::Window(int width_,
            int height_,
            const std::string& title_):
    width(width_),
    height(height_),
    title(title_),
    window(nullptr)
{
    window = glfwCreateWindow(width,
                              height,
                              title.c_str(),
                              NULL,
                              NULL);
    // Check for faults
    if(window == nullptr)
    {
        std::string errorMsg = 
        "Failed to create window for the following config: ";
        throw std::runtime_error(errorMsg << *this);
    }
}

Window::~Window()
{
    
}

int Window::getWidth() const
{
    return width;
}

int Window::getHeight() const
{
    return height;
}

std::string Window::getTitle() const
{
    return title;
}

const GLFWwindow * const Window::getWindow() const
{
    return window;
}

std::ostream& Window::operator<<(std::ostream& os_,
                                 const Window& window_)
{
    std::string windowConfigStr;
    windowConfigStr = std::format("================\n"
    "Title: {}\n"
    "Width: {}\n"
    "Height: {}\n"
    "================\n",
    window_.getTitle(),
    window_.getWidth(),
    window_.getHeight());

}

} // archon