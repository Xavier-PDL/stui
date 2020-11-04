#include <ui_text.hpp>

ui_text::ui_text(ui_base* pParent, const std::string& text)
    : ui_base(pParent)
{
    this->text = text;
}

ui_text::ui_text(ui_base* pParent, const std::string& text, int x, int y)
    : ui_base(pParent, x, y)
{
    this->text = text;
}


void ui_text::setText(std::string&& text)
{
    this->text = text;
}

void ui_text::draw()
{
    vec2i offset;
    if(pParent) offset = getParent()->getPos();
    mvprintw( offset.y + y, offset.x + x, text.c_str());
}
