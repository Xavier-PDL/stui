#ifndef __UI_TEXT__
#define __UI_TEXT__
#include "ui_base.hpp"

class ui_window;
/**
 * Text object that prints relative to a parent window.
 */
class ui_text : public ui_base
{
    std::string text;
public:
    ui_text(ui_base* pParent, const std::string& text);
    ui_text(ui_base* pParent, const std::string& text, int x, int y);

    void setText(std::string&& text);
    void draw();
};
 
#endif
