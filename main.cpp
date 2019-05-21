#include "graphics.hpp"
#include "number.hpp"
#include "widget.hpp"
#include "iostream"
#include "vector"
#include "list.hpp"
#include "gdraw.hpp"
#include "comp.hpp"

using namespace genv;
using namespace std;

int main()
{
    gout.open(800,800);
    vector<Widget*>w;
    Widget* w0 = new gdraw(10,10,30,30);
    w.push_back(w0);
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
