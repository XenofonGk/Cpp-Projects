#ifndef ENTRY_H
#define ENTRY_H
#include <iostream>

namespace LexiStore {

    class Entry{
    private:
        char* m_key{};
        char* m_value{};
    public:
        Entry();
        Entry(const char* key,const char* value);
        Entry(const Entry& src);
        Entry& operator=(const Entry& src);
        ~Entry();

        const char* getValue() const;
        std::ostream& display(std::ostream& os = std::cout) const;
        bool operator==(const char* key) const;
    };

}


#endif