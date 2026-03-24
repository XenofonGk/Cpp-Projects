#ifndef KVSTORE_H
#define KVSTORE_H
#include <iostream>
#include "Entry.h"

namespace LexiStore {
    
    class KVStore {
        LexiStore::Entry* m_entries{};
        int m_size{};
    public:
        KVStore();
        KVStore(const KVStore& src);
        KVStore& operator=(const KVStore& src);
        ~KVStore();
        KVStore& operator+=(const LexiStore::Entry& entry);
        const char* operator[](const char* key) const;
        std::ostream& display(std::ostream& os = std::cout) const;
    };
}
#endif