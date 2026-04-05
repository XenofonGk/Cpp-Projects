#include <iostream>
#include <cstring>
#include <iomanip>
#include "Menu.h"
#include "Utils.h"
namespace Restaurant {

 MenuItem::MenuItem(const char* content, unsigned numOfIndentation, unsigned sizeOfIndentation, int rowNum) {
     if (content != nullptr && content[0] != '\0') {
         m_numOfIndentation = numOfIndentation;
         m_sizeOfIndentation = sizeOfIndentation;
         m_rowNum = rowNum;
         while (*content == ' ' || *content == '\t' || *content == '\n' ||
             *content == '\r' || *content == '\f' || *content == '\v') {
             content++;
         }
         m_content = new char[strlen(content) + 1];
         strcpy(m_content, content);

     }
     else {
         m_numOfIndentation = 0;
         m_sizeOfIndentation = 0;
         m_rowNum = 0;
         m_content = nullptr;
     }
 }
    MenuItem::operator bool() const { if (m_content != nullptr) {
        return true; } else { return false; }
    }

    std::ostream& MenuItem::display(std::ostream& os) const {
        if (m_content != nullptr) {
            for (unsigned i = 0; i < m_numOfIndentation * m_sizeOfIndentation; i++) {
                os << ' ';
            }
            if (m_rowNum >= 0) {
                os << std::setw(2) << m_rowNum << "- ";
            }
            os << m_content;
        }
        return os;
    }

   MenuItem::~MenuItem(){
        delete[] m_content;
    }


    Menu::Menu(const char* title, const char* exitOpt,
    unsigned int indent, unsigned int indentSize) 
    : m_indentation(indent), m_indentSize(indentSize),
    m_numItems(0), m_title(title, indent, indentSize, -1),
    m_exitOption(exitOpt, indent, indentSize, 0),
    m_entryPrompt("> ", indent, indentSize, -1)
    {
       for (unsigned int i = 0; i < MaximumNumberOfMenuItems; i++)
       {
        m_items[i] = nullptr; 
       }
    }

    Menu::~Menu()
    {
        for (unsigned int i = 0; i< MaximumNumberOfMenuItems; i++)
        {
            delete m_items[i];
            m_items[i] = nullptr;
        }
    }

    Menu& Menu::operator<<(const char* menuItemContent)
    {
        if (m_numItems < MaximumNumberOfMenuItems){
    m_items[m_numItems] =  new MenuItem(menuItemContent,m_indentation,m_indentSize,m_numItems + 1);
            m_numItems++;
        }
        return *this;
    }
    size_t Menu::select() const
    {
        if (m_title){
            m_title.display() << std::endl;
        }
        for (unsigned int i = 0; i<m_numItems; i++)
        {
            m_items[i]->display() << std::endl;
        }
        m_exitOption.display() << std::endl;
        m_entryPrompt.display();
        
        return (size_t)Utils::getInt(0,m_numItems);
    }

    size_t operator<<(std::ostream& ostr, const Menu& m)
    {
          size_t selection = 0;
          if (&ostr == &std::cout) {
            selection = m.select();
          }

          return selection;
    }
}
