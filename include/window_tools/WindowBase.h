// Rename to Window after
#ifndef ARCHON_WINDOW_TOOLS_I_WINDOW_H_
#define ARCHON_WINDOW_TOOLS_I_WINDOW_H_
#include <string>
namespace archon
{
namespace window_tools
{

/**
 * Needs comments and cleaning up
 */
class WindowBase
{
public:
    // Below must be overriden
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual const std::string& getTitle() const = 0;
    virtual void setHeight(int height_) = 0;
    virtual void setWidth(int width_) = 0;
    virtual void setTitle(const std::string& title_) = 0;
    virtual void makeActive() = 0;
    virtual bool shouldClose() const = 0;
    virtual void swapBuffers() = 0;

private:
};

} // window_tools
} // archon


#endif // ARCHON_WINDOW_TOOLS_I_WINDOW_H_