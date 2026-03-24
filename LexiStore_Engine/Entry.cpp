#include <iostream>
#include <cstring>
#include "Entry.h"

namespace LexiStore {

    Entry::Entry(){
        *this = Entry(nullptr,nullptr);
    }
    Entry::Entry(const char* key,const char* value){
        if (key != nullptr){
            m_key = new char[strlen(key) + 1];
            strcpy(m_key,key);
        } else {
            m_key = nullptr;
        }
        if (value != nullptr){
            m_value = new char[strlen(value) + 1];
            strcpy(m_value,value);
        } else {
            m_value = nullptr;
        }
    }
    Entry::Entry(const Entry& src){
        if (src.m_key != nullptr){
            m_key = new char[strlen(src.m_key) + 1];
            strcpy(m_key,src.m_key);
        } else {
            m_key = nullptr;
        }
        if (src.m_value != nullptr){
            m_value = new char[strlen(src.m_value) + 1];
            strcpy(m_value, src.m_value);
        } else {
            m_value = nullptr;
        }
    }

    Entry& Entry::operator=(const Entry& src){
        if (this != &src){
            delete[] m_key;
            delete[] m_value;

                   if (src.m_key != nullptr){
            m_key = new char[strlen(src.m_key) + 1];
            strcpy(m_key,src.m_key);
        } else {
            m_key = nullptr;
        }
        if (src.m_value != nullptr){
            m_value = new char[strlen(src.m_value) + 1];
            strcpy(m_value, src.m_value);
        } else {
            m_value = nullptr;
        }
        
        }
        return *this;
    }
    Entry::~Entry(){
        delete[] m_value;
        m_value = nullptr;
        delete[] m_key;
        m_key = nullptr;
    }

    const char* Entry::getValue() const {
        return m_value;
    }

    std::ostream& Entry::display(std::ostream& os) const{
        os << "Key: " << m_key << " has Value: " << m_value << std::endl;

        return os;
    }

    bool Entry::operator==(const char* key) const{
        if (m_key && key){
           return strcmp(m_key,key) == 0;
        } else {
            return false;
        }
    }


}