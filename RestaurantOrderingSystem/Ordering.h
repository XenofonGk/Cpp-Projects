#ifndef ORDERING_H
#define ORDERING_H
#include "Food.h"
#include "Drink.h"
#include "constants.h"

namespace Restaurant {
    class Ordering {
        unsigned int m_foodCount{};
        unsigned int m_drinkCount{};
        unsigned int m_billableCount{};
        unsigned int m_billSerial{1};

        Food* m_foodArray{};
        Drink* m_drinkArray{};

        Billable* m_billItems[MaximumNumberOfMenuItems]{};

        void printBillTitle(std::ostream& ost) const;
        void printTotals(std::ostream& ost,double total) const;
        size_t countRecords(const char* file) const;
        
    public:
        Ordering(const char* drinkFile, const char* foodFile);
        Ordering(const Ordering&) = delete;
        Ordering& operator=(const Ordering) = delete;
        ~Ordering();
        
        operator bool() const;
        size_t noOfBillItems() const;
        bool hasUnsavedBill() const;

        void listFoods() const;
        void listDrinks() const;
        void orderFood();
        void orderDrink();
        void printBill(std::ostream& ost) const;
        void resetBill();
    };
}
#endif