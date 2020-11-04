#ifndef __UI_MAIN__
#define __UI_MAIN__
#include <curses.h>
#include <panel.h>
#include <menu.h>
#include <vector>
#include "ui_window.hpp"

class ui_main : public ui_window
{
    ui_window* pMainWindow;
public:
    ui_main();
    void init();
    void draw();
    void update(int width, int height);
    void destroy();

private:

};

#endif //__UI_MAIN__
