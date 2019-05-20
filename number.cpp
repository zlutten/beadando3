#include "number.hpp"
#include "widget.hpp"
#include "vector"
#include "graphics.hpp"


number::number(int x, int y, int sx, int sy, std::string text, int counter,int cmin, int cmax)
{
    this-> x = x;
    this-> y = y;
    this-> sx = sx;
    this-> sy = sy;
    this-> szoveg = text;
    this-> pushed = false;
    //this-> hover = false;
    this->counter = counter;
    this-> cmin = cmin;
    this-> cmax = cmax;
}
void number::draw()
{
    gout << color(255,255,255) << move_to(x,y) << box(sx,sy);
    gout << move_to(x+sx/2,y) << color(0,255,0)<<box(sx/2,sy/2) << move_to(x+3*sx/4,y+sy/4) << color(0,0,0) << text("+");
    gout << move_to(x+sx/2,y+sy/2) << color(255,0,0) << box(sx/2,sy/2) << move_to(x+3*sx/4,y+3*sy/4) << color(0,0,0)<<text("-");
    szoveg = std::to_string(counter);
    gout << move_to(x+sx/6,y+2*sy/3) << color(0,0,0) << text(szoveg);



    /*gout << color(255,255,255);                   //kiirodoboz
    gout << move_to(x-sx,y) << box(sx,sy);
    if (pushed == false)    // sima gombok kiirasa
    {
        gout << color(255,255,255);
        gout<<move_to(x,y)<<box(sx,sy);
        gout<<move_to(x+sx/2,y+sy/2)<<color(0,0,0)<<text(szoveg);
    }
    if (pushed == true && szoveg == "+") //nyomásra zöld lesz
    {
    gout << color(0,255,0);
    gout<<move_to(x,y)<<box(sx,sy);
    gout<<move_to(x+sx/2,y+sy/2)<<color(0,0,0)<<text(szoveg);
    }
    else if (pushed == true && szoveg == "-")  // nyomásra piros lesz
    {
        gout << color(255,0,0);
        gout<<move_to(x,y)<<box(sx,sy);
        gout<<move_to(x+sx/2,y+sy/2)<<color(0,0,0)<<text(szoveg);
    }*/
}
void number::handle(genv::event ev)
{
    if (ev.pos_x>x+sx/2 && ev.pos_x<x+sx && ev.pos_y>y && ev.pos_y<y+sy/2 && ev.button == btn_left)
        counter++;

    if (ev.pos_x>x+sx/2 && ev.pos_x<x+sx && ev.pos_y>y+sy/2 && ev.pos_y<y+sy && ev.button == btn_left)
        counter--;
    if (counter >= cmax)
        counter = cmax;
    if (counter <= cmin)
        counter = cmin;
}

