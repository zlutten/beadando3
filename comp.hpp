#ifndef COMP_HPP_INCLUDED
#define COMP_HPP_INCLUDED
#include "vector"
#include "widget.hpp"
#include "graphics.hpp"

class comp : public Widget
{
protected:
    struct ginfo
    {
    int px,py;
    bool checked;
    bool o;
    };
public:
    comp(std::vector<ginfo>g);
    void draw();
    void handle(genv::event ev);
};



#endif // COMP_HPP_INCLUDED
