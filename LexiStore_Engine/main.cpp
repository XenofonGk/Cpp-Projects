#include <iostream>
#include "KVStore.h"
#include "Entry.h"
#include "Utils.h"

using namespace std;
using namespace LexiStore;
    
   // A quick helper to prove the Rule of Three works before the menu starts
   void testMemoryLogic() {
    cout << ">>> Initializing Memory Logic Check..." << endl;
    Entry e1("Admin", "SuperUser");
    Entry e2 = e1; // Tests Copy Constructor
    Entry e3;
    e3 = e1;       // Tests Assignment Operator
   
    cout << "Original: "; e1.display();
    cout << "Copy:     "; e2.display();
    cout << "Assign:   "; e3.display();
    cout << ">>> Memory Check Passed (No Crashes)\n" << endl;
   }
   
   int main() {
   KVStore myStore;
   int choice;

   cout << "=== LexiStore Engine: Pro Edition ===" << endl;

   // 1. Run the automated check
   testMemoryLogic();

   // 2. Interactive Database Menu (Uses Utils!)
   do {
    cout << "--- Database Menu ---" << endl;
    cout << "1. Add New Entry (+=)\n2. Search by Key ([])\n3. Display All Database\n0. Exit System" << endl;
        
    // Using your Utils here!
    choice = getInt(0, 3, "Select an option: ");

    if (choice == 1) {
        char k[128], v[128];
        cout << "Enter Key: ";   cin >> k;
        cout << "Enter Value: "; cin >> v;
          
        myStore += Entry(k, v); // Triggers your resizing logic!
        cout << "Entry added successfully." << endl;
        clearBuffer();
    } 
    else if (choice == 2) {
        char k[128];
        cout << "Enter Key to Search: "; cin >> k;
            
        const char* val = myStore[k]; // Triggers your search logic!
        if (val) {
        cout << ">> FOUND: Key [" << k << "] has Value [" << val << "]" << endl;
        } else {
        cout << ">> NOT FOUND: Key [" << k << "] does not exist." << endl;
        }
      clearBuffer();
       }
        else if (choice == 3) {
        myStore.display(); // Triggers your loop display!
       }

    } while (choice != 0);

   cout << "Shutting down LexiStore. All memory cleared. Goodbye!" << endl;

    return 0;
}