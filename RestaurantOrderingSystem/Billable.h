#ifndef BILLABLE_H
#define BILLABLE_H
#include <iostream>
#include <fstream>

namespace Restaurant {
class Billable {
    char* m_name{};
    double m_price{};
protected:
    void price(double value);
    void name(const char* name);
public:
    Billable();
    Billable(const Billable& src);
    Billable& operator=(const Billable& src);
    virtual ~Billable();
    virtual double price() const;
    virtual std::ostream& print(std::ostream& ost = std::cout) const = 0;
    virtual bool order() = 0;
    virtual bool ordered() const = 0;
    virtual std::ifstream& read(std::ifstream& file) = 0;
    operator const char*() const;
};

    double operator+(double money, const Billable& B);
    double& operator+=(double& money, const Billable& B);
    std::ostream& operator<<(std::ostream& ost, const Billable& B);
}
#endif