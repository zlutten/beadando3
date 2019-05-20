#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"

using namespace genv;

class Widget
{
protected:
int x,y,sx,sy;
public:
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    //virtual std::string visszateres() = 0;
};


#endif // WIDGET_HPP_INCLUDED
