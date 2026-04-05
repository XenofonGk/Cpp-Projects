#ifndef RESTAURANT_MENU_H
#define RESTAURANT_MENU_H

#include <iostream>
#include "constants.h"
namespace Restaurant{

class Menu;

class MenuItem {
private:
    char* m_content{};
    unsigned int m_numOfIndentation{};
    unsigned int m_sizeOfIndentation{};
    int m_rowNum{};
    MenuItem(const char*, unsigned , unsigned , int);
    ~MenuItem();
    MenuItem(const MenuItem&) = delete;
   MenuItem& operator=(const MenuItem&) = delete;
    operator bool() const;
    std::ostream& display(std::ostream& os = std::cout) const;

    friend class Menu;
};

  class Menu {
    unsigned int m_indentation{};
    unsigned int m_indentSize{};
    unsigned int m_numItems{};

    MenuItem m_title;
    MenuItem m_exitOption;
    MenuItem m_entryPrompt;

    MenuItem* m_items[MaximumNumberOfMenuItems]{};

    public:
    Menu(const char* title, const char* exitOpt = "Exit",
    unsigned int indent = 0, unsigned int indentSize = 3);

    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    ~Menu();

    Menu& operator<<(const char* menuItemContent);
    size_t select() const;
};
    size_t operator<<(std::ostream& ostr, const Menu& m);



}

#endif