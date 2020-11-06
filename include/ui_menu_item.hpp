
#ifndef __UI_MENU_ITEM__
#define __UI_MENU_ITEM__

#include <ui_base.hpp>

#define E_NO_CALLBACK 1

class ui_menu_item
{
    std::string name;
    std::string desc;
    void* pArgs = nullptr;
    using menu_item_callback = int(void*);
    menu_item_callback* pCallback = nullptr;
public:
    ui_menu_item(int pCallback(void*), void* pArgs, std::string&& name);
    ui_menu_item(int pCallback(void*), std::string&& name, std::string&& desc);
    const std::string& getName();
    const std::string& getDesc();
    int call();
};

#endif // __UI_MENU_ITEM__
