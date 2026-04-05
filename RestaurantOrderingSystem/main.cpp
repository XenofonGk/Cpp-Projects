#include <iostream>
#include "Ordering.h"
#include "Menu.h"

using namespace std;
using namespace Restaurant;

int main() {
    Ordering ord("drinks.csv", "foods.csv");

    if (!ord) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }

    Menu mainMenu("C++ Restaurant Ordering System ","End Program", 0);
    mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";

    bool done = false;
    while (!done){
        size_t selection = mainMenu.select();

        switch (selection){
            case 1: { 
                Menu orderMenu("Order Menu", "Back to main menu", 2);
                orderMenu << "Food" << "Drink";

                bool backToMain = false;
                while (!backToMain) {
                size_t subSelection = orderMenu.select();

                if (subSelection == 1) {
                ord.orderFood();
                } 
                else if (subSelection == 2) {
                ord.orderDrink();
                } 
                else if (subSelection == 0) {
                backToMain = true;
                }
            }
            break; 
            }
              case 2:
                ord.printBill(std::cout);
                break;
            case 3:
               ord.resetBill();
                break;
            case 4:
                ord.listFoods();
                break;
            case 5:
                ord.listDrinks();
                break;
            case 0:
                    if (ord.hasUnsavedBill()) {
                    Menu confirm("You have bills that are not saved. Are you sue you want to exit?", "No", 0);
                    confirm << "Yes";

                    if (confirm.select() == 1) {
                        done = true;
                    }
                    } else {
                        done = true;
                    }
                    break;
            default:
                break;
        }
    }
    return 0;
}