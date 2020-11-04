#include <ui_main.hpp>
#include <curses.h>
#include <pthread.h>

ui_main::ui_main()
     : ui_window(0, 0, getmaxx(stdscr), getmaxy(stdscr))
{
}

void ui_main::init()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    start_color();
    use_default_colors();
    init_pair(1, 2, -1);
    pMainWindow = new ui_window(0, 1,
                                getmaxx(stdscr) - 1, 
                                getmaxy(stdscr) - 3,
                                true);
    pMainWindow->addText("Testing top text!!!", 1, 1);
    pMainWindow->addText("Another test...", 1, 2);
    pMainWindow->addText("And another one!", 1, 3);
}

void ui_main::draw()
{
    ui_print_text_xy(0, 0,
                     1, A_BOLD | A_UNDERLINE,
                     "bm");
    ui_print_text_xy(0, getmaxy(stdscr) - 1,
                     1, A_BOLD | A_UNDERLINE,
                     "Bottom Text");
    pMainWindow->draw();
}

void ui_main::update(int width, int height)
{
    pMainWindow->setSize(width-1, height-3);
    pMainWindow->clear();
}

void ui_main::destroy()
{
    if(pMainWindow)
    {    
        delete pMainWindow;
        pMainWindow = nullptr;
    }
}
