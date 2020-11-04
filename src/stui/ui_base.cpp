#include <ui_base.hpp>

ui_base::ui_base(ui_base* pParent)
{
    this->pParent = pParent;
}

ui_base::ui_base(ui_base* pParent, int x, int y)
    : x(x), y(y)
{
    this->pParent = pParent;
}

ui_base::~ui_base()
{
    destroy();
}

vec2i ui_base::getPos()
{
    vec2i pos(x,y);
    if(pParent)
        pos += pParent->getPos();
    return pos;
}

void ui_base::destroy()
{
    for(auto p : vChildren)
        delete p;
    vChildren.clear();
}

ui_base* ui_base::getParent()
{
    return pParent;
}
