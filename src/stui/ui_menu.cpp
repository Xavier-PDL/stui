#include "ui_util.hpp"
#include <curses.h>
#include <ui_menu.hpp>

ui_menu::ui_menu(int x, int y)
    : ui_base(nullptr, x, y)
{
}

ui_menu::ui_menu(ui_base* pParent, int x, int y)
    : ui_base(pParent, x, y)
{
}

void ui_menu::show()
{
    visible = true;
}

void ui_menu::hide()
{
    visible = false;
}

bool ui_menu::isVisible()
{
    return visible;
}

int ui_menu::drive(EMenuNav mn)
{
    switch(mn)
    {
        case MD_UP:
        {
            hlIndex = clamp(hlIndex-1, 0, (int)menuItems.size()-1);
            break;
        }
        case MD_DOWN:
        {
            hlIndex = clamp(hlIndex+1, 0, (int)menuItems.size()-1);
            break;
        }
        case MD_ENTER:
        {
            return menuItems[hlIndex].call();
        }
    }
    return 0;
}

void ui_menu::addMenuOption(std::string&& name)
{
    addMenuOption(std::move(name), nullptr, nullptr);
}

void ui_menu::addMenuOption(std::string&& name,
                            int pCallback(void*),
                            void* pArgs)
{
    width = std::max(width, name.length());
    menuItems.push_back(ui_menu_item(pCallback, pArgs, std::move(name)));
}

void ui_menu::addMenuOption(std::string&& name, std::string&& desc)
{
    addMenuOption(std::move(name), std::move(desc), nullptr);
}

void ui_menu::addMenuOption(std::string&& name,
                            std::string&& desc, 
                            int callback (void*))
{
    width = std::max(width, name.length());
    menuItems.push_back(ui_menu_item(callback,
                                     std::move(name), 
                                     std::move(desc)));
}

void ui_menu::setOption(MenuOption option)
{
    menuOptions ^= option;
}

void ui_menu::setOptions(MenuOption options)
{
    menuOptions = options;
}

void ui_menu::draw()
{
    for(size_t i = 0; i < menuItems.size(); i++)
    {
        int attr = 0;
        if(i == hlIndex)
            attr = A_REVERSE;
        auto name = menuItems[i].getName();
        auto len = name.length();
        if(len > width)
        {
            name = name.substr(0, width - 3);
            name.append("...");
        }
        else
        {
            std::string pad(width - len, ' ');
            name.append(pad);
        }

        ui_print_text_xy(x, y+i, 0, attr, name.c_str());
    }
}
