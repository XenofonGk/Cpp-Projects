#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "Ordering.h"
#include "Menu.h"

namespace Restaurant {

    void Ordering::printBillTitle(std::ostream& ost) const {
        ost << "Bill # ";
        ost.fill('0');
        ost.width(3);
        ost << m_billSerial << " =============================" << std::endl;
        ost.fill(' '); 
    }

    void Ordering::printTotals(std::ostream& ost, double total) const {
        double tax = total * Tax; // Tax is in constants.h
        ost << std::fixed << std::setprecision(2); // Set decimal places
        
        ost << std::left << std::setw(20) << "" << std::setw(10) << "Total: " << std::right << std::setw(10) << total << std::endl;
        ost << std::left << std::setw(20) << "" << std::setw(10) << "Tax: " << std::right << std::setw(10) << tax << std::endl;
        ost << std::left << std::setw(20) << "" << std::setw(10) << "Total+Tax:" << std::right << std::setw(10) << (total + tax) << std::endl;
        ost << "========================================" << std::endl;
    }

    
    size_t Ordering::countRecords(const char* file) const {
        size_t count = 0;
        std::ifstream f(file);
        char ch;

        while (f.get(ch)) {
            if (ch == '\n'){
                count++;
            }
        }
        return count;
    }

    Ordering::Ordering(const char* drinkFile, const char* foodFile){
      size_t dCount = countRecords(drinkFile);
      size_t fCount = countRecords(foodFile);

      std::ifstream dfile(drinkFile);
      std::ifstream ffile(foodFile);

      if (dfile && ffile) {
        m_drinkArray = new Drink[dCount];
        m_foodArray = new Food[fCount];
        unsigned int dRead = 0;
        for (size_t i = 0; i < dCount && dfile; i++){
            if (m_drinkArray[i].read(dfile)){
                dRead++;
            }
        }
        unsigned int fRead = 0;
        for (size_t i=0; i< fCount && ffile; i++){
            if (m_foodArray[i].read(ffile)){
                fRead++;
            }
        }
      

      if (dRead!= dCount || fRead!= fCount){
        delete[] m_drinkArray;
        delete[] m_foodArray;
        m_drinkArray = nullptr;
        m_foodArray = nullptr;
        m_drinkCount = m_foodCount = 0;
        } else {
        m_drinkCount = dRead;
        m_foodCount = fRead;
        }
      }
    } 

    Ordering::~Ordering(){
        delete[] m_drinkArray;
        delete[] m_foodArray;

        for (unsigned int i = 0; i < m_billableCount; i++){
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }
    }

     Ordering::operator bool() const{
        if (m_foodArray != nullptr && m_drinkArray != nullptr){
            return true;
        }
        return false;
     }

        size_t Ordering::noOfBillItems() const{
            return m_billableCount;
        }

        bool Ordering::hasUnsavedBill() const{
            if (m_billableCount > 0){
                return true;
            }
            return false;
        }

        void Ordering::listFoods() const{
            std::cout << "List Of Avaiable Meals" << std::endl;
            std::cout << "========================================" << std::endl;;
            for (unsigned int i = 0; i < m_foodCount; i++){
                m_foodArray[i].print();
                std::cout << std::endl;
            }

            std::cout << "========================================" << std::endl;

        }
        void Ordering::listDrinks() const{
              std::cout << "List Of Avaiable Drinks" << std::endl << "========================================" << std::endl ;
            for (unsigned int i = 0; i < m_drinkCount; i++){
                m_drinkArray[i].print();
                std::cout << std::endl;

            }

            std::cout << "========================================" << std::endl;;

        }

        void Ordering::orderFood(){
            Menu foodMenu("Food Menu", "Back to Order", 2);

            for (unsigned int i = 0; i < m_foodCount; i++) {
                foodMenu << (const char*)m_foodArray[i];
            }
            size_t selection = foodMenu.select();

            if (selection > 0){
                m_billItems[m_billableCount] = new Food(m_foodArray[selection - 1]);
                if (m_billItems[m_billableCount]->order()) {
                    m_billableCount++;
                } else {
                    delete m_billItems[m_billableCount];
                    m_billItems[m_billableCount] = nullptr;
                }
            }
        }

        void Ordering::orderDrink(){
            Menu drinkMenu("Drink Menu", "Back to Order", 2);

            for (unsigned int i = 0; i < m_drinkCount; i++) {
                drinkMenu << (const char*)m_drinkArray[i];
            }
            size_t selection = drinkMenu.select();

            if (selection > 0){
                m_billItems[m_billableCount] = new Drink(m_drinkArray[selection - 1]);
                if (m_billItems[m_billableCount]->order()) {
                    m_billableCount++;
                } else {
                    delete m_billItems[m_billableCount];
                    m_billItems[m_billableCount] = nullptr;
                }
            }
        }
        

        void Ordering::printBill(std::ostream& ost) const{
            double total = 0.0;

                printBillTitle(ost);
                for (unsigned int i = 0; i < m_billableCount; i++){
                    m_billItems[i]->print(ost);
                    total += m_billItems[i]->price();
                    ost << std::endl;
                }
                printTotals(ost, total);
        }
        
        void Ordering::resetBill() {
    char filename[21] = "bill_";
    size_t temp = m_billSerial;
    int cnt = 5;
    int length;

    size_t digitCheck = temp;
    do {
       cnt++;
       digitCheck /= 10;
    } while (digitCheck > 0);
    
    length = cnt;
    
    size_t billNoCopy = m_billSerial;
    while (billNoCopy > 0) {
       filename[--cnt] = (billNoCopy % 10) + '0';
       billNoCopy /= 10;
    }

    if (m_billSerial == 0) {
       filename[--cnt] = '0';
    }

    const char* extension = ".txt";
    for (int i = 0; extension[i]; i++) {
       filename[length++] = extension[i];
    }
    filename[length] = '\0';

    std::ofstream file(filename);
    if (file) {
        printBill(file);
        
        std::cout << "Saved bill number " << m_billSerial << std::endl;
        
        for (unsigned int i = 0; i < m_billableCount; i++) {
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }
        
        m_billSerial++;      
        m_billableCount = 0; 
        
        std::cout << "Starting bill number " << m_billSerial << std::endl;
    }
}



}

