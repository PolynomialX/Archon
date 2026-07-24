#ifndef ARCHON_WINDOW_MANAGER_H
#define ARCHON_WINDOW_MANAGER_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "Window.h"
namespace archon
{
namespace window_tools
{
    /**
     * @class WindowManager
     *  Aims to orchestrate the creation, management
     * & destruction of windows.
     * Note, further development may be needed for multiple windows concurrently.
     * This is merely a step in that direction.
     */
class WindowManager
{
public:
    WindowManager();
    virtual ~WindowManager();

    /**
     * @brief createWindow
     *      Function used to instantiate a new window
     *      Note this function does set the active context to this window.
     * @param title_ - window title
     * @param width_ - window width (pixels)
     * @param height_ - window height (pixels)
     */
    void createWindow(const std::string& title_,
                      int width_,
                      int height_);
    /**
     * @brief setWindowContext
     *        Use this function to make a chosen window the active OpenGL context...
     * @param title_ - title of the window you want to set as the active context
     */
    void setWindowContext(const std::string& title_);
    /**
     * @brief getWindow
     *  Currently returns a reference to a desired window
     * @param title_ - title of desired window
     */
    Window& getWindow(const std::string& title_);
private:
    /**
     * @brief initGLAD
     *        Method to initialise GLAD. Must be called *after* a window is created.
     * @return bool - flags whether initialisation was successful.
     */
    bool initGLAD();
    // Actual store of Window objects
    // TODO: Make it a vector of unique_ptrs
    std::vector<std::unique_ptr<Window> > windows;
    // Mapping from Window titles -> indices.
    std::unordered_map<std::string, std::size_t> windowMap;
};

} // window_tools
} // archon
#endif // ARCHON_WINDOW_MANAGER_H