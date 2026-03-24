#include <iostream>
#include <cstring>
#include "KVStore.h"
#include "Entry.h"

namespace LexiStore {

    KVStore::KVStore() {
        m_entries = nullptr;
        m_size = 0;
    }

    KVStore::KVStore(const KVStore& src) {
        m_size = src.m_size;
        if (src.m_entries) {
            m_entries = new Entry[m_size];
            for (int i = 0; i < m_size; i++)
                m_entries[i] = src.m_entries[i];
        } else {
            m_entries = nullptr;
        }
    }

    KVStore& KVStore::operator=(const KVStore& src) {
        if (this != &src) {
            delete[] m_entries;

            m_size = src.m_size;
            if (src.m_entries) {
                m_entries = new Entry[m_size];
                for (int i = 0; i < m_size; i++) {
                    m_entries[i] = src.m_entries[i];
                }
            } else {
                m_entries = nullptr;
            }
        }
        return *this;
    }

    KVStore::~KVStore() {
        delete[] m_entries;
        m_entries = nullptr;
    }

    KVStore& KVStore::operator+=(const Entry& entry) {
        Entry* temp = new Entry[m_size + 1];
        for (int i = 0; i < m_size; i++) {
            temp[i] = m_entries[i];
        }
        temp[m_size] = entry;
        delete[] m_entries;
        m_entries = temp;
        m_size++;

        return *this;
    }

    const char* KVStore::operator[](const char* key) const {
        for (int i = 0; i < m_size; i++) {
            if (m_entries[i] == key) {
                return m_entries[i].getValue();
            }
        }
        return nullptr;
    }

    std::ostream& KVStore::display(std::ostream& os) const {
        os << "--- LexiStore Database (" << m_size << " Entries) ---" << std::endl;
        for (int i = 0; i < m_size; i++) {
            m_entries[i].display(os);
        }
        return os;
    }

}