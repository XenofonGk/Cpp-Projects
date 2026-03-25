#ifndef ARENA_H
#define ARENA_H
#include "Mage.h"
#include "Warrior.h"

    namespace Arena{

        class Arena{
        Character** m_roster{};
        int m_count{};
    public:
        Arena();
        Arena(const Arena& src) = delete;
        Arena& operator=(const Arena& src) = delete;
        ~Arena();
        Arena& operator+=(Character*);
        void load(const char* filename);
        void save(const char* filename) const;
        void display(std::ostream& os = std::cout) const;
        };
    }

#endif