#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include "vector"
#include "widget.hpp"
#include "graphics.hpp"

class dlist : public Widget
{
protected:
    std::vector<std::string>items;
public:
    dlist(int x, int y, int sx, int sy, std::vector<std::string>items);
    void draw();
    void handle(genv::event ev);
    std::string szoveg;
    bool open,selected;
    int selectednr, first;

};


#endif // LIST_HPP_INCLUDED
