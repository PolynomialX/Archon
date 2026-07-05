#ifndef ARCHON_WINDOW_H
#define ARCHON_WINDOW_H

#include <memory>
#include <string>
#include <exception>
#include <sstream>
#include <iostream>
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
    void setWidth(int width_);
    int getHeight() const;
    void setHeight(int height_);
    const std::string& getTitle() const;

    // Used to print out config
    friend std::ostream& operator<<(std::ostream& os_, 
                                    const Window& window_);
private:
    
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // archon
#endif // ARCHON_WINDOW_H