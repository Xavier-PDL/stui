#include <ui_util.hpp>

void ui_print_text(int color_pair, int attr,
                   const char* fmt, ...)
{
    std::string buffer;
    get_formatted_string(buffer, fmt, args);

    if(color_pair)
        attron(COLOR_PAIR(color_pair));
    if (attr)
        attron(attr);

    printw(buffer.c_str());

    if(color_pair)
        attroff(COLOR_PAIR(color_pair));
    if (attr)
        attroff(attr);
}

void ui_print_text_xy(int x, int y, int color_pair,
                      int attr, const char* fmt, ...)
{
    std::string buffer;
    get_formatted_string(buffer, fmt, args);

    if(color_pair)
        attron(COLOR_PAIR(color_pair));
    if (attr)
        attron(attr);

    mvprintw(y, x, buffer.c_str());

    if(color_pair)
        attroff(COLOR_PAIR(color_pair));
    if (attr)
        attroff(attr);
}
