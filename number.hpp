#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"


class number : public Widget
{
protected:

public:
    number(int x, int y, int sx, int sy,std::string text, int counter, int cmin, int cmax);
    void draw();
    void handle(genv::event ev);
    std::string szoveg;
    bool pushed;
    bool hover;
    int counter;
    int cmin,cmax;

    //int szamlalo;
};


#endif // BUTTON_HPP_INCLUDED
