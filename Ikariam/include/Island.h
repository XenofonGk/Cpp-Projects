#ifndef ISLAND_H
#define ISLAND_H
#include "Building.h"
namespace Ikariam {

    class Island {
        char* m_name{};
        Building** m_buildings{};
        int m_count{};
        int m_capacity{};
    public:
        Island(const char* name,int capacity=10);
        ~Island();
        Island(const Island& src);
        Island& operator=(const Island& src);

        void addBuilding(const Building& b);
        void display(std::ostream& os) const;

    };

}

#endif