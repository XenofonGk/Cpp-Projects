#ifndef DRINK_H
#define DRINK_H
#include "Billable.h"

namespace Restaurant {
class Drink : public Billable {
    char m_size{};
public:
    Drink();
    double price() const override;
    std::ostream& print(std::ostream& ost = std::cout) const override;
    bool order() override; 
    bool ordered() const override;
    std::ifstream& read(std::ifstream& file) override;
};
}
#endif