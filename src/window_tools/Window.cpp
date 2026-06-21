#include "window_tools/Window.h"
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
        std::stringstream ss;
        ss << errorMsg << *this;
        throw std::runtime_error(ss.str());
    }

    // Print out window config
    std::cout << "Created window with config: \n"
    << *this << std::endl;
}

Window::~Window()
{
    
}

int Window::getWidth() const
{
    return width;
}

void Window::setWidth(int width_)
{
    this->width = width_;
    glfwMakeContextCurrent(this->getWindow());
    glfwSetWindowSize(this->window, width, height);
    glViewport(0, 0, width, height);
}

int Window::getHeight() const
{
    return height;
}

void Window::setHeight(int height_)
{
    this->height = height_;
    glfwMakeContextCurrent(this->getWindow());
    glfwSetWindowSize(this->window, width, height);
    glViewport(0, 0, width, height);
    
}

std::string Window::getTitle() const
{
    return title;
}

GLFWwindow * Window::getWindow()
{
    return window;
}

std::ostream& operator<<(std::ostream& os_,
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
    return os_ << windowConfigStr;
}



} // archon