#ifndef __UI_WINDOW__
#define __UI_WINDOW__
#include "ui_text.hpp"
//#include "ui_menu.hpp"

class ui_text;
class ui_window : public ui_base
{
    int width, height;
    bool hasBorder = false;

public:
    ui_window(int x, int y,
              int width, int height,
              bool hasBorder = false);
    ui_window(ui_base* pParent,
              int x, int y,
              int width, int height,
              bool hasBorder = false);

    void addText(const std::string& text, int x, int y);

    void clear();
    virtual void draw();
    void setSize(int width, int height);

private:
    void drawBorder();
};

#endif // __UI_WINDOW__
