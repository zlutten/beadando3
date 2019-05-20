#ifndef SQUARES_HPP_INCLUDED
#define SQUARES_HPP_INCLUDED
#include "vector"
#include "widget.hpp"
#include "graphics.hpp"

squares : public Widget
{
protected:

public:
    gdraw(int x, int y, int sx, int sy);
    void draw();
    void handle();
    int counter();
}


#endif // SQUARES_HPP_INCLUDED
