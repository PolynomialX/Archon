#ifndef RENDERING_RENDER_ORCHESTRATOR_H
#define RENDERING_RENDER_ORCHESTRATOR_H
#include "window_tools/WindowBase.h"
// Simple class for the time being
namespace archon
{
class RenderOrchestrator
{
public:
    RenderOrchestrator() = default;
    ~RenderOrchestrator() = default;

    static void simpleRenderLoop(window_tools::WindowBase& windowToRenderTo_);
private:

};
} // archon


#endif // RENDERING_RENDER_ORCHESTRATOR_H