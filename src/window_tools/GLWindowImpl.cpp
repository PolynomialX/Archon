#include "window_tools/GLWindowImpl.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <format>
#include <iostream>
#include <sstream>
namespace archon
{
namespace window_tools
{
namespace archon_gl
{


class GLWindow::GLWindowImpl
{
public:
    GLWindowImpl(int width_,
                 int height_,
                 const std::string& title_):
    width(width_),
    height(height_),
    title(title_)
    {
        pGLFWwindow = glfwCreateWindow(width,
                    height,
                    title.c_str(),
                    NULL,
                    NULL);
        // Check for faults
        if(pGLFWwindow == nullptr)
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
    ~GLWindowImpl()
    {

    }
    
    GLWindowImpl(GLWindowImpl &&impl_) = default;

    GLWindowImpl(const GLWindowImpl& impl_) = default;

    int getWidth() const
    {
        return width;
    }

    void setWidth(int width_)
    {
        this->width = width_;
        glfwMakeContextCurrent(pGLFWwindow);
        glfwSetWindowSize(pGLFWwindow, width, height);
        glViewport(0, 0, width, height);
    } 

    int getHeight() const
    {
        return height;
    }

    void setHeight(int height_)
    {
        this->height = height_;
        glfwMakeContextCurrent(pGLFWwindow);
        glfwSetWindowSize(pGLFWwindow, width, height);
        glViewport(0, 0, width, height);
    }

    const std::string& getTitle() const
    {
        return title;
    }

    void makeActive()
    {
        glfwMakeContextCurrent(pGLFWwindow);
        glViewport(0,
                   0,
                   width,
                   height);
    }

    bool isValid()
    {
        if(pGLFWwindow)
        {
            return true;
        }
        return false;
    }

    static void framebufferSizeCallback(GLFWwindow* window_,
                                 int width_,
                                 int height_)
    {
        glViewport(0, 0, width_, height_);
    }

    void setFramebufferSizeCallback()
    {
        glfwSetFramebufferSizeCallback(this->pGLFWwindow, 
                                       framebufferSizeCallback);
    }

    bool shouldClose()
    {
        return glfwWindowShouldClose(this->pGLFWwindow);
    }

    void swapBuffers()
    {
        glfwSwapBuffers(this->pGLFWwindow);
    }

    friend std::ostream& operator<<(std::ostream& os_, 
                                const GLWindowImpl& impl_)
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

    void setTitle(const std::string& title_)
    {
        title = title_;
        glfwSetWindowTitle(pGLFWwindow,
                            title.c_str());
    }
private:
    int width;
    int height;
    std::string title;
    GLFWwindow* pGLFWwindow;
};

GLWindow::GLWindow(int width_,
                  int height_,
                  const std::string& title_):
    pImpl(std::make_unique<GLWindowImpl>(width_,
                           height_,
                           title_))
{

}
GLWindow::GLWindow(GLWindow&& glWindow_)
{
    this->pImpl.swap(glWindow_.pImpl);
}

GLWindow::~GLWindow()
{

}

int GLWindow::getWidth() const
{
    return pImpl->getWidth();
}

int GLWindow::getHeight() const
{
    return pImpl->getHeight();
}

const std::string& GLWindow::getTitle() const
{
    return pImpl->getTitle();
}

void GLWindow::setHeight(int height_)
{
    pImpl->setHeight(height_);
}

void GLWindow::setTitle(const std::string& title_)
{
    pImpl->setTitle(title_);
}

void GLWindow::makeActive()
{
    pImpl->makeActive();
}

bool GLWindow::shouldClose() const
{
    return pImpl->shouldClose();
}

void GLWindow::swapBuffers()
{
    pImpl->swapBuffers();
}

} // archon_gl
} // window_tools
} // archon