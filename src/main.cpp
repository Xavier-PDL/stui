#include <iostream>
#include <filesystem>
#include <curses.h>
#include <panel.h>
#include <menu.h>
#include <ui_main.hpp>
#include <ui_menu.hpp>

const char* choices[] =
{
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Exit"
};
int main(int argc, const char** argv)
{
    int ch;
    ui_main gui;
    gui.init();
    gui.draw();

    ui_menu menu(25,3);
    menu.addMenuOption("Simple Option 1");
    menu.addMenuOption("Option 2 with callback",
                       [](void* pData){mvprintw(8,5, "%s", pData); return 0;},
                       (void*)"Args for callback...");
    menu.draw();
    refresh();
    while((ch = getch()) != 'q')
    {
        gui.update(getmaxx(stdscr), getmaxy(stdscr));
        gui.draw();
        menu.show();
        refresh();
        switch(ch)
        {
            case '\n':
            {
                mvprintw(7, 5, "Pressing ENTER");
                menu.drive(MD_ENTER);
                break;
            }
            case 'k':
            case KEY_UP:
            {
                if(menu.isVisible())
                {
                    menu.drive(MD_UP);
                    break;
                }
            }
            case 'j':
            case KEY_DOWN:
            {
                if(menu.isVisible())
                {
                    menu.drive(MD_DOWN);
                    break;
                }
            }
        }
        menu.draw();
    }
    gui.destroy();
    endwin();

    return 0;
}

int SqliteCallback(void* userArgs,
                   int numColumns,
                   char** szColumnData,
                   char** szColumnName)
{
    for(int i = 0; i < numColumns; i++)
    {
        printf("%s: %s\n", szColumnName[i], szColumnData[i]);
    }
    return 0;
}
