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
    this->c = c;
}


void gdraw::draw()
{
    for (int j = 0; j<15; j++)
    {
        for (int i = 0; i<15; i++)
        {
            gout << move_to(x+i*35,y+j*35) << color(255,255,255) << box(sx,sy);
            gout << move_to(x+i*35+5,y+j*35+5) << color (0,0,0) << box(sx-10,sy-10);
            for (int k = 0; k<c.size(); k++)
            {
                if (c[k].checked == true && c[k].o == false)
                {
                    gout<< move_to(c[k].cx,c[k].cy) << color(255,255,255) << line_to(c[k].cx+30,c[k].cy+30);
                    gout<< move_to(c[k].cx+30,c[k].cy) << line_to(c[k].cx,c[k].cy+30);
                }
                else if (c[k].checked == true && c[k].o == true)
                {
                    gout<< move_to(c[k].cx+10,c[k].cy+20) << color(255,255,255) << text("0");
                }
                else
                {
                    gout << move_to(x+i*35+5,y+j*35+5) << color (0,0,0) << box(sx-10,sy-10);
                }
            }

        }
    }
}

void gdraw::handle(event ev)
{
    for (int j = 0; j<15; j++)
    {
        for (int i = 0; i<15; i++)
        {
            if (ev.pos_x>x+i*35 && ev.pos_x<x+i*35+30 && ev.pos_y>y+j*35 && ev.pos_y<y+j*35+30 && ev.button == btn_left)
            {
                counter++;
                if (counter%2 != 0)
                {
                    checked tmp;
                    tmp.cx = x+i*35;
                    tmp.cy = y+j*35;
                    tmp.checked = true;
                    tmp.o=false;
                    c.push_back(tmp);
                }
                else
                {
                    checked tmp;
                    tmp.cx = x+i*35;
                    tmp.cy = y+j*35;
                    tmp.checked = true;
                    tmp.o=true;
                    c.push_back(tmp);
                }


            }
        }
    }
}
