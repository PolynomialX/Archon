#ifndef ARCHON_WINDOW_TOOLS_GL_WINDOW_IMPL_H_
#define ARCHON_WINDOW_TOOLS_GL_WINDOW_IMPL_H_

#include "window_tools/WindowBase.h"
#include <memory>
namespace archon
{
namespace archon_gl
{

class GLWindow : public WindowBase
{
public:
    GLWindow(int width_,
             int height_,
             const std::string& title_);
    GLWindow(GLWindow&& glWindow_);
    virtual ~GLWindow();
    
    virtual int getWidth() const;
    virtual int getHeight() const;
    virtual const std::string& getTitle() const;
    virtual void setHeight(int height_) override;
    virtual void setWidth(int width_) override;
    virtual void setTitle(const std::string& title_) override;
    virtual void makeActive() override;
    virtual bool shouldClose() const override;
    virtual void swapBuffers() override;
private:
    class GLWindowImpl;
    std::unique_ptr<GLWindowImpl> pImpl;
};

} // archon_gl
} // archon



#endif // ARCHON_WINDOW_TOOLS_GL_WINDOW_IMPL_H_