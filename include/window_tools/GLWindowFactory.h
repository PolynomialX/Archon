#ifndef ARCHON_WINDOW_TOOLS_GL_WINDOW_FACTORY_H_
#define ARCHON_WINDOW_TOOLS_GL_WINDOW_FACTORY_H_

#include "window_tools/WindowFactory.h"
#include "window_tools/GLWindow.h"

namespace archon
{
namespace window_tools
{
namespace archon_gl
{

class GLWindowFactory: public WindowFactory
{
    GLWindowFactory();
    virtual ~GLWindowFactory();
    virtual std::unique_ptr<WindowBase> createWindow(const int width_,
                                                     const int height_,
                                                     const std::string& title_) override;
};

} // archon_gl
} // window_tools
} // archon
#endif // ARCHON_WINDOW_TOOLS_GL_WINDOW_FACTORY_H-