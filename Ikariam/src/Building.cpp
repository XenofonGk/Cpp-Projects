#include "../include/Building.h"
#include <iostream>
#include <cstring>

namespace Ikariam {
    Building::Building(const char* name, int lvl){
        if(name != nullptr) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name,name);
        } else {
            m_name = nullptr;
        }
        m_level = lvl;
    }

    Building::~Building(){
        delete[] m_name;
    }

    Building::Building(const Building& src){
        m_level = src.m_level;

        if (src.m_name != nullptr){
        m_name = new char[strlen(src.m_name) + 1];
        strcpy(m_name, src.m_name);
    } else {
        m_name = nullptr;
    }
    }

    Building& Building::operator=(const Building& src){
        if (this != &src) {
            delete[] m_name;
                 m_level = src.m_level;

        if (src.m_name != nullptr){
        m_name = new char[strlen(src.m_name) + 1];
        strcpy(m_name, src.m_name);
    } else {
        m_name = nullptr;
    }
    }
    return *this;
    }

    const char* Building::getName() const{
        return m_name;
    }
    void Building::print(std::ostream& os) const{
        os << "Name: " << (m_name ? m_name : "N/A") << " | LVL: " << m_level << std::endl;
    }

    std::ostream& operator<<(std::ostream& os, const Building& b){
        b.print(os);
        return os;
    }

}