#include <iomanip>
#include "Drink.h"
#include "Utils.h"
#include "Menu.h"
#include <iostream>

using namespace std;

namespace Restaurant {
    Drink::Drink(){
        m_size = '\0';
    }

    std::ostream& Drink::print(std::ostream& ost) const {
        ost.setf(std::ios::fixed);
        ost.precision(2);
        ost << std::left << std::setfill('.') << std::setw(28) << (const char*)*this;

        if (ordered()) {
            switch (m_size) {
            case 'S':
                ost << "SML..";
                break;
            case 'M':
                ost << "MID..";
                break;
            case 'L':
                ost << "LRG..";
                break;
            case 'X':
                ost << "XLR..";
                break;
            default:
                ost << ".....";
                break;
            }
        }
        else {
            ost << ".....";
        }
        ost << std::right << std::setfill(' ') << std::setw(7) << price();
        return ost;
    }

    bool Drink::order() {
        Menu m("Drink Size Selection", "Back", 1, 9);
        m << "Small" << "Medium" << "Larg" << "Extra Large";
        int choice = (int)m.select();

        if (choice == 1) {
            m_size = 'S';
        }
        else if (choice == 2) {
            m_size = 'M';
        }
        else if (choice == 3) {
            m_size = 'L';
        }
        else if (choice == 4) {
            m_size = 'X';
        }
        else {
            m_size = '\0';
        }

        return ordered();
    }

    bool Drink::ordered() const {
        return m_size != '\0';
    }
    std::ifstream& Drink::read(std::ifstream& file){
      m_size = '\0';
      Billable::read(file);
        return file;
    }

      double Drink::price() const{
    double bPrice = Billable::price();
    if (!ordered() || m_size == 'L') return bPrice;

    if (m_size == 'S') return bPrice * 0.5;
    if (m_size == 'M') return bPrice * 0.75;
    if (m_size == 'X') return bPrice * 1.5;

    return bPrice;
    }
}
