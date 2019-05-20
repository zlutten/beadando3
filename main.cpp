#include "graphics.hpp"
#include "number.hpp"
#include "widget.hpp"
#include "iostream"
#include "vector"
#include "list.hpp"

using namespace genv;
using namespace std;

int main()
{
    gout.open(600,600);
    vector<string>items;
    vector<string>items2;
    string l1 = "hello";
    string l2 = "ez egy";
    string l3 = "teszt";
    string l4 = "dropdown";
    string l5 = "menu";
    string l6 = "remelem";
    string l7 = "vegre nem fog";
    string l8 = "alul kilepni";
    items.push_back(l1);
    items.push_back(l2);
    items.push_back(l3);
    items.push_back(l4);
    items.push_back(l5);
    items.push_back(l6);
    items.push_back(l7);
    items.push_back(l8);
    string k1 = "masik";
    string k2 = "random";
    string k3 = "lista ami";
    string k4 = "kell a";
    string k5 = "teszteleshez";
    string k6 = "tdlskjfdlkfkdls";
    items2.push_back(k1);
    items2.push_back(k2);
    items2.push_back(k3);
    items2.push_back(k4);
    items2.push_back(k5);
    items2.push_back(k6);
    vector<Widget*>w;
    Widget* w0 = new number(200,300,50,40,"",0,-10,10);
    Widget* w1 = new number(400,300,50,40,"",0,-20,5);
    Widget* w2 = new dlist(50,100,200,30,items);
    Widget* w3 = new dlist(300,100,200,30,items2);
    w.push_back(w0);
    w.push_back(w1);
    w.push_back(w2);
    w.push_back(w3);
    event ev;
    while(gin >> ev)
    {
        for (int i = 0; i<w.size(); i++)
        {
            w[i]->draw();
            w[i]->handle(ev);
        }
        gout<<refresh;
    }
    return 0;
}
