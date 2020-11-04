#ifndef __UI_BASE__
#define __UI_BASE__
#include <string>
#include <vector>
#include <curses.h>
#include "ui_util.hpp"

class ui_base
{
protected:
    int x = 0;
    int y = 0;
    ui_base* pParent = nullptr;
    std::vector<ui_base*> vChildren;
public:
    ui_base(ui_base* pParent);
    ui_base(ui_base* pParent, int x, int y);
    virtual ~ui_base();

    vec2i getPos();
    
    virtual void draw(){}
    virtual ui_base* getParent();
    template<class T>
    T* getParent();

protected:
    virtual void destroy();
};


template<class T>
T* ui_base::getParent()
{
    return reinterpret_cast<T*>(pParent);
}

#endif // __UI_BASE__
