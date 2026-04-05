#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "Billable.h"

namespace Restaurant {

class Food : public Billable {
    bool m_ordered{};
    bool m_child{};
    char* m_customize{};
public:
    Food();
    Food(const Food& src);
    Food& operator=(const Food& src);
    ~Food();
    std::ostream& print(std::ostream& ost = std::cout) const override;
    bool order() override;
    bool ordered() const override;
    std::ifstream& read(std::ifstream& file) override;
    double price() const override;
};

}


#endif