#include "../include/Academy.h"
#include <iostream>

namespace Ikariam {

    Academy::Academy(const char* name, int lvl,double research)
    : Building(name,lvl) {
        m_research = research;
    }

    void Academy::print(std::ostream& os) const{
        Building::print(os);

        os << "Research: " << m_research;
    }

    Building* Academy::clone() const{
        return new Academy(*this);
    }

        double Academy::getResearch() const{
            return m_research;
        }
}