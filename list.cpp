#include "widget.hpp"
#include "iostream"
#include "vector"
#include "graphics.hpp"
#include "list.hpp"

using namespace genv;

dlist::dlist(int x, int y, int sx, int sy, std::vector<std::string>items)
{
    this-> x = x;
    this-> y = y;
    this-> sx=sx;
    this-> sy=sy;
    this-> items = items;
    this-> open = false;
    this-> selected = false;
    this-> selectednr = 0;
    this-> first = 0;
}

void dlist::draw()
{
    gout << move_to(x,y) << color(255,255,255) << box(sx,sy) << move_to(x+10,y+20) <<color(0,0,0)<< text(items[selectednr]);
    gout << move_to(x+sx,y) <<color(255,255,0) << box(40,sy) << move_to(x+sx+5,y+20)<< color(0,0,0) << text("open");
    if (open == true)
    {
        for (int i = 0; i<4; i++)
        {
            gout << move_to(x,y+i*sy) << color(255,255,255) << box(sx,sy);
            gout << move_to(x+10,y+i*sy+20) << color(0,0,0)<< text(items[first+i]);
        }
        if (selectednr>=3)
        {
            gout << move_to(x,y+3*sy) << color(51,255,51) << box(sx,sy);
            gout << move_to(x+10,y+3*sy+20) << color(0,0,0)<< text(items[selectednr]);
        }
        else
        {
            gout << move_to(x,y+selectednr*sy) << color(51,255,51) << box(sx,sy);
            gout << move_to(x+10,y+selectednr*sy+20) << color(0,0,0)<< text(items[selectednr]);
        }
        gout << move_to(x+sx,y) <<color(255,255,0) << box(40,sy) << move_to(x+sx+5,y+20)<< color(0,0,0) << text("select");
        gout << move_to(x+sx,y+sy) <<color(255,255,0) << box(40,sy) << move_to(x+sx+5,y+sy+20)<< color(0,0,0) << text("up");
        gout << move_to(x+sx,y+3*sy) <<color(255,255,0) << box(40,sy) << move_to(x+sx+5,y+3*sy+20)<< color(0,0,0) << text("down");
    }
    else
        gout << move_to(x,y+sy) << color(0,0,0) << box(sx+40,3*sy);
}

void dlist::handle(event ev)
{
    if(ev.pos_x>x+sx && ev.pos_x<x+sx+40 && ev.pos_y>y && ev.pos_y<y+sy && ev.button == btn_left && open != true)
        open = true;
    else if(ev.pos_x>x+sx && ev.pos_x<x+sx+40 && ev.pos_y>y && ev.pos_y<y+sy && ev.button == btn_left && open != false)
        open = false;
    for (int i = 0; i<4; i++)
    {
        if(ev.pos_x>x && ev.pos_x<x+sx && ev.pos_y>y+i*sy && ev.pos_y<y+(i+1)*sy && ev.button == btn_left && open == true)
        {
            open = false;
            selectednr = first+i;
            //std::cout << selectednr << std::endl;
        }
    }
    if(ev.pos_x>x+sx && ev.pos_x<x+sx+40 && ev.pos_y>y+sy && ev.pos_y<y+2*sy && ev.button == btn_left && open == true)
    {
        selectednr--;
        first --;
    }
    if(ev.pos_x>x+sx && ev.pos_x<x+sx+40 && ev.pos_y>y+3*sy && ev.pos_y<y+4*sy && ev.button == btn_left && open == true)
    {
        selectednr++;
        first++;
    }
    if(ev.keycode == key_up && open == true)
    {
        selectednr--;
        first--;
    }
    if(ev.keycode == key_down && open == true)
    {
        selectednr++;
        first++;
    }
    if (ev.keycode == key_enter && open == true)
        open = false;
    if (selectednr < 0)
        selectednr = 0;
    if (selectednr > items.size()-1)
        selectednr=items.size()-1;
    if (first>selectednr-3)
        first = selectednr-3;
    if (first<0)
        first = 0;
}
