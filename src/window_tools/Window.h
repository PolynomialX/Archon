#ifndef ARCHON_WINDOW_H
#define ARCHON_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <format>
#include <exception>
/**
 * @class Window
 *  Used to encapsulate attributes for a window to render to
 */
namespace archon
{
class Window
{
public:
    Window(int width_,
         int height_,
         const std::string& title_);
    virtual ~Window();

    // Getters & setters
    int getWidth() const;
    int getHeight() const;
    std::string getTitle() const;
    const GLFWwindow * const getWindow() const;

    // Used to print out config
    friend std::ostream& operator<<(std::ostream& os_, 
                                    const Window& window_);
private:

    int width;
    int height;
    std::string title;
    GLFWwindow* window;
};
} // archon
#endif // ARCHON_WINDOW_H