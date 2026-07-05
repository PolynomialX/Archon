#include "window_tools/Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <format>
namespace archon
{

class Window::Impl
{
public:
    Impl(int width_,
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
    virtual ~Impl()
    {

    }

    int getWidth() const
    {
        return width;
    }

    void setWidth(int width_)
    {
        this->width = width_;
        glfwMakeContextCurrent(this->getWindow());
        glfwSetWindowSize(this->window, width, height);
        glViewport(0, 0, width, height);
    } 

    int getHeight() const
    {
        return height;
    }

    void setHeight(int height_)
    {
        this->height = height_;
        glfwMakeContextCurrent(this->getWindow());
        glfwSetWindowSize(this->window, width, height);
        glViewport(0, 0, width, height);
    }

    const std::string& getTitle() const
    {
        return title;
    }

    friend std::ostream& operator<<(std::ostream& os_, 
                                const Impl& impl_)
    {
        std::string windowConfigStr;
        windowConfigStr = std::format("================\n"
        "Title: {}\n"
        "Width: {}\n"
        "Height: {}\n"
        "================\n",
        impl_.getTitle(),
        impl_.getWidth(),
        impl_.getHeight());
        return os_ << windowConfigStr;
    }
private:
    int width;
    int height;
    std::string title;
    GLFWwindow* window;
};

Window::Window(int width_,
            int height_,
            const std::string& title_):
    pImpl(std::make_unique<Impl>(width_,
                                height_,
                                title_))
{

}

Window::~Window()
{
    
}

int Window::getWidth() const
{
    return pImpl->getWidth();
}

void Window::setWidth(int width_)
{
    pImpl->setWidth(width_);
}

int Window::getHeight() const
{
    return pImpl->getHeight();
}

void Window::setHeight(int height_)
{
    pImpl->setHeight(height_);    
}

const std::string& Window::getTitle() const
{
    return pImpl->getTitle();
}

// GLFWwindow * Window::getWindow()
// {
//     return window;
// }

std::ostream& operator<<(std::ostream& os_,
                                 const Window& window_)
{
    return os_ << window_.pImpl;
}



} // archon