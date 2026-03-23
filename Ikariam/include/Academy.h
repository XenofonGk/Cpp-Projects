#ifndef ACADEMY_H
#define ACADEMY_H
#include "Building.h"

namespace Ikariam {
    // Academy IS A Building
class Academy : public Building {
    double m_research{};
    public:
    // Constructor
    Academy(const char* name, int lvl, double research);
    // Polymorphism
    virtual void print(std::ostream& os) const override;
    virtual Building* clone() const override;
    // Unique Getter
    double getResearch() const;
};
}

#endif