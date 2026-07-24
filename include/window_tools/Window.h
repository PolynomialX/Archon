#ifndef ARCHON_WINDOW_H
#define ARCHON_WINDOW_H

#include <memory>
#include <string>
#include <exception>
#include <sstream>
#include <iostream>
/**
 * @class Window
 *  Used to encapsulate attributes & methods for a window to render to
 */
namespace archon
{
namespace window_tools
{

class Window
{
public:
    /**
     * @brief Default constructor
     *        Constructs a window of width width_ pixels
     *        height height_ pixels & title title_
     * @param width_ - width of window (in pixels)
     * @param height_ - height of window (in pixels)
     * @param title_ - title of window
     */
    Window(int width_,
         int height_,
         const std::string& title_);
    
    /**
     * @brief Move Constructor
     * @param window_ - instance of window to move contruct from
     */
    Window(Window && window_);

    /**
     * @brief Copy Constructor
     *        Not currently implemented?
     * @param window_ - Window instance to construct from / copy from
     */
    Window(const Window& window_) = default;

    /**
     * @brief Destructor
     */
    ~Window();

    // Getters & setters
    /**
     * @brief getWidth
     * @return - width of window (in pixels)
     */
    int getWidth() const;

    /**
     * @brief setWidth
     * @param width_ - new width of window (in pixels)
     * @return void
     */
    void setWidth(int width_);

    /**
     * @brief getHeight
     * @return height of window (in pixels)
     */
    int getHeight() const;

    /**
     * @brief setHeight
     * @param height_ - new height of window (in pixels)
     */
    void setHeight(int height_);

    /**
     * @brief getTitle
     * @return string - title of the window
     */
    const std::string& getTitle() const;

    /**
     * @brief shouldClose
     *        Flags whether the window should close.
     * @return bool - true if window should close, else false
     */
    bool shouldClose();
    
    /**
     * @brief makeActive 
     *        Makes the current window the active context.
     * @return void
     */
    void makeActive();
    
    /**
     * @brief isValid
     *        Checks whether Window has been constructed (validly).
     * @return bool - true if valid, false else.
     */
    bool isValid() const;

    /**
     * @brief setFrameBufferSizeCallback
     *        Set the callback function for when the window is resized.
     * @return void
     */
    void setFramebufferSizeCallback();

    /**
     * @brief swapBuffers
     *        Swap between front & back buffer.
     * @return void
     */
    void swapBuffers();
    
    /**
     * @brief Overriden output operator
     *        Prints to an ostream the config of the window
     *  MAKE THIS A NON MEMBER FUNCTION
     * @return ostream object
     */
    friend std::ostream& operator<<(std::ostream& os_, 
                                    const Window& window_);
private:
    
    /**
     * Opaque pointer to implmentation
     */
    class Impl;
    std::unique_ptr<Impl> pImpl;

};

} // window_tools
} // archon

#endif // ARCHON_WINDOW_H