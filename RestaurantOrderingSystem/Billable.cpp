#include <cstring>
#include "Billable.h"
#include <iostream>

using namespace std;

namespace Restaurant {

    std::ostream& operator<<(std::ostream& ost, const Billable& B) {
        return B.print(ost);
    }

    void Billable::price(double value) {
        m_price = value;
    }

    void Billable::name(const char* name) {
        if (m_name != name) {
            delete[] m_name;
            m_name = nullptr;
            if (name != nullptr && name[0] != '\0') {
                m_name = new char[strlen(name) + 1];
                strcpy(m_name, name);
            }
        }
    }

    std::ifstream& Billable::read(std::ifstream& file) {
        char buff[1000]{};
        double buffPrice{};
        if (file.getline(buff, 1000, ',')) {
            name(buff);
            file >> buffPrice;
            file.ignore(1000, '\n');
            price(buffPrice);
        }
        return file;
    }

    Billable::Billable(){
        m_name = nullptr;
        m_price = 0.0;
        }

    Billable::Billable(const Billable& src){
        m_name = nullptr;
        *this = src;
    }

    Billable& Billable::operator=(const Billable& src){
        if ( this != &src){
            this->name(src.m_name);
            m_price = src.m_price;
        }
        return *this;
    }

    Billable::~Billable(){
        delete[] m_name;
    }

    double Billable::price() const{
        return m_price;
    }

    Billable::operator const char*() const{
        return m_name;
    }

    double operator+(double money, const Billable& B){
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B){
         money += B.price(); 
        return money;
    }

}
