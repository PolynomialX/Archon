#ifndef ARCHON_WINDOW_TOOLS_WINDOW_FACTORY_H_
#define ARCHON_WINDOW_TOOLS_WINDOW_FACTORY_H_
#include "window_tools/Window.h"
#include <memory>
#include <string>
namespace archon
{
namespace window_tools
{
/**
 * @class WindowFactory
 * @brief Factory Interface class for Window objects
 */
class WindowFactory
{
public:
    virtual ~WindowFactory() = default;
    virtual std::unique_ptr<Window> createWindow(const int width_,
                                                     const int height_,
                                                     const std::string& title_) = 0;
private:

};
} // window_tools
} // archon

#endif // ARCHON_WINDOW_TOOLS_WINDOW_FACTORY_H_