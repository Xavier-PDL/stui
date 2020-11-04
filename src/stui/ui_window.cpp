#include <ui_window.hpp>

ui_window::ui_window(int x, int y,
                     int width, int height,
                     bool hasBorder)
    :
    ui_base(nullptr, x, y),
    width(width), height(height),
    hasBorder(hasBorder)
{
}

ui_window::ui_window(ui_base* pParent,
                     int x, int y,
                     int width, int height,
                     bool hasBorder)
    :
    ui_base(pParent, x, y),
    width(width), height(height),
    hasBorder(hasBorder)
{
}

void ui_window::addText(const std::string& text, int x, int y)
{
    vChildren.push_back(new ui_text(this, text, x, y));
}

void ui_window::clear()
{
    for(int i = x; i <= x + width; i++)
    {
        for(int j = y; j <= y + height; j++)
        {
            mvaddch(j, i, ' ');
        }
    }
}

void ui_window::draw()
{
    clear();
    for(auto pChild : vChildren)
        pChild->draw();
    if(hasBorder)
        drawBorder();
}

void ui_window::setSize(int width, int height)
{
    clear();
    this->width = width;
    this->height = height;
}

void ui_window::drawBorder()
{
    // borders
    mvhline(y,        x+1,   0, width-1);
    mvhline(y+height, x+1,   0, width-1);
    mvvline(y+1,      x,     0, height-1);
    mvvline(y+1,      width, 0, height-1);
    // corners
    mvaddch(y,        x,     ACS_ULCORNER);
    mvaddch(y,        width, ACS_URCORNER);
    mvaddch(y+height, x,     ACS_LLCORNER);
    mvaddch(y+height, width, ACS_LRCORNER);
}
