#include <iostream>
#include <filesystem>
#include <curses.h>
#include <panel.h>
#include <menu.h>
#include "ui_main.hpp"

const char* choices[] = {
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
    
    /*
    int nChoices = 5;
    ITEM* pItems[6]{0};
    for(int i = 0; i < nChoices; i++)
        pItems[i] = new_item(choices[i], nullptr);
    MENU* pMenu = new_menu(pItems);
    post_menu(pMenu);
    */
    /*
    ui_menu menu(25,3);
    menu.addMenuOption("Option 1", 0);
    menu.addMenuOption("Option 2", 0);
    menu.addMenuOption("Super duper long Option 3", 0);
    menu.addMenuOption("Option 4", 0);
    menu.addMenuOption("","");
    menu.finalizeMenu();
    menu.draw();
    menu.refresh();
    */
    refresh();
    while((ch = getch()) != 'q')
    {
        gui.update(getmaxx(stdscr), getmaxy(stdscr)); 
        gui.draw();
        //menu.draw();
        refresh();
        //wrefresh(menu.pWindow);
        //menu.refresh();
    }
    gui.destroy();
    endwin();


    // check and load local config file if it exists
    // read in available libraries from library listing
    // if there is none, ask user if they would like to create a new library
    // once library has been loaded, load up that library's database
    // show a listing of books and available operations:
    // add, remove, open, edit, etc...

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
