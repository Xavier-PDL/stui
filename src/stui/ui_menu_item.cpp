#include <ui_menu_item.hpp>


ui_menu_item::ui_menu_item(int pCallback(void*), void* pArgs, std::string&& name)
    : name(std::move(name))
{
    this->pArgs = pArgs;
    this->pCallback = pCallback;
}

ui_menu_item::ui_menu_item(int pCallback(void*), std::string&& name, std::string&& desc)
    : name(std::move(name)), desc(std::move(desc))
{
    this->pCallback = pCallback;
}

const std::string& ui_menu_item::getName()
{
    return name;
}

const std::string& ui_menu_item::getDesc()
{
    return desc;
}

int ui_menu_item::call()
{
    if(pCallback)
        return pCallback(pArgs);
    return E_NO_CALLBACK;
}
