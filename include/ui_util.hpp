#ifndef __UI_UTIL__
#define __UI_UTIL__
#include <curses.h>
#include <string>
#include <vec2.hpp>

/**
 * Kind of like snprintf but easier to use and just as safe.
 */
#define get_formatted_string(s, fmt, ...)\
{\
    va_list args;\
    va_start(args, fmt);\
    va_list acopy;\
    va_copy(acopy, args);\
    s.resize(vsnprintf(nullptr, 0, fmt, args) + 1);\
    va_end(args);\
    vsnprintf(s.data(), s.size(), fmt, acopy);\
    va_end(acopy);\
}\

void ui_print_text(int color_pair, int attr,
                   const char* fmt, ...);
void ui_print_text_xy(int x, int y,
                      int color_pair, int attr,
                      const char* fmt, ...);

#endif //__UI_UTIL__
