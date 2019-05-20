#include "number.hpp"
#include "widget.hpp"
#include "vector"
#include "graphics.hpp"
#include "gdraw.hpp"

gdraw::gdraw(int x, int y, int sx, int sy)
{
this-> x = x;
this-> y = y;
this-> sx = sx;
this-> sy = sy;
this-> counter = 0;
}

void gdraw::draw()
{
    for (int i = 0; i<15; i++)
    {
        gout << move_to(x+i*5,y) << color(255,255,255) << box(sx,sy);
        gout << move_to(x+i*5,y+i*5) << color (0,0,0) << box(sx-10,sy-10);
    }


}

void gdraw::handle(event ev)

{

}
