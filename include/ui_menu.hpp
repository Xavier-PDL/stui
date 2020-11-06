#ifndef __UI_MENU__
#define __UI_MENU__

#include <ui_base.hpp>
#include <ui_menu_item.hpp>

using MenuOption = unsigned short;

#define MO_SHOWDESC (1<<0);

enum EMenuNav
{
    MD_UP,
    MD_DOWN,
    MD_ENTER
};

class ui_menu : public ui_base
{
    size_t width = 10;
    size_t hlIndex = 0;
    bool visible = false;
    MenuOption menuOptions; // bitfield
    std::vector<ui_menu_item> menuItems;
public:
    ui_menu(int x, int y);
    ui_menu(ui_base* pParent, int x, int y);
    
    void show();
    void hide();
    bool isVisible();
    int drive(EMenuNav mn);
    
    void addMenuOption(std::string&& name);
    void addMenuOption(std::string&& name, int(void*), void* pArgs);
    void addMenuOption(std::string&& name, std::string&& desc);
    void addMenuOption(std::string&& name, std::string&& desc, int(void*));

    void setOption(MenuOption option);
    void setOptions(MenuOption options);

    virtual void draw();
};

#endif // __UI_MENU__
