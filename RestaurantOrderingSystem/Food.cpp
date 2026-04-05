#include <iomanip>
#include <cstring>
#include "Food.h"
#include <iostream>
#include "Utils.h"
#include "Menu.h"
using namespace std;

namespace Restaurant
{

    Food::Food()
    {
        m_ordered = false;
        m_child = false;
        m_customize = nullptr;
    }

    Food::Food(const Food &src)
    {
        m_customize = nullptr;
        *this = src;
    }

    Food& Food::operator=(const Food& src)
    {
        if (this != &src)
        {
            Billable::operator=(src);
            delete[] m_customize;

            m_ordered = src.m_ordered;
            m_child = src.m_child;

            if (src.m_customize != nullptr)
            {
                m_customize = new char[strlen(src.m_customize) + 1];
                strcpy(m_customize, src.m_customize);
            }
            else
            {
                m_customize = nullptr;
            }
        }
        return *this;
    }

    Food::~Food()
    {
        delete[] m_customize;
        m_customize = nullptr;
    }

    std::ostream& Food::print(std::ostream &ost) const
    {
        ost.setf(std::ios::fixed);
        ost.precision(2);
        ost << std::left << std::setfill('.') << std::setw(28) << (const char *)*this;

        if (ordered() && m_child)
        {
            ost << "Child";
        }
        else if (ordered() && !m_child)
        {
            ost << "Adult";
        }
        else
        {
            ost << ".....";
        }
        ost << std::right << std::setfill(' ') << std::setw(7) << price();
        if (m_customize != nullptr && &ost == &cout)
        {
            int len = ut.strlen(m_customize);
            if (len < 30 && len > 0)
            {
                ost << " >> " << m_customize;
            }
            else if (len > 30)
            {
                ost << " >> ";
                ost.write(m_customize, 30);
            }
        }
        return ost;
    }

    bool Food::order()
    {
        Menu m("Food Size Selection", "Back", 1, 9);
        m << "Adult" << "Child";
        int choice = (int)m.select();

        if (choice == 1)
        {
            m_ordered = true;
            m_child = false;
        }
        else if (choice == 2)
        {
            m_ordered = true;
            m_child = true;
        }
        else
        {
            delete[] m_customize;
            m_customize = nullptr;
            m_ordered = false;
        }


        if (m_ordered)
        {
            char buff[1000]{};
            cout << "Special instructions" << endl;
            cout << "> ";
            cin.getline(buff, 1000);
            if (buff[0] == '\0')
            {
                delete[] m_customize;
                m_customize = nullptr;
            }
            else
            {
                ut.alocpy(m_customize, buff);
            }
        }

        return m_ordered;
    }

    bool Food::ordered() const
    {
        return m_ordered;
    }

    std::ifstream& Food::read(std::ifstream &file)
    {
    
            m_child = false;
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
        
            Billable::read(file);
        return file;
    }
    double Food::price() const
    {
        if (m_child)
        {
            return Billable::price() / 2;
        }
        return Billable::price();
    }

}
