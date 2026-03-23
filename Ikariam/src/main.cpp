#include <iostream>
#include "../include/Academy.h"
#include "../include/Island.h"

using namespace Ikariam;

int main() {
    // 1. Create an Island
    Island myHome("Ithaca", 5);

    // 2. Create an Academy (on the stack)
    // Name: "Great Library", Level: 5, Research: 15.5
    Academy lib("Great Library", 5, 15.5);

    // 3. Add it to the island
    // addBuilding will CLONE the Academy, making a heap copy
    myHome.addBuilding(lib);

    std::cout << "--- Original Island ---" << std::endl;
    myHome.display(std::cout);

    // 4. Test Copy Constructor (Deep Copy)
    std::cout << "\n--- Testing Copy Constructor (Copying Ithaca to Sicily) ---" << std::endl;
    Island copyIsland = myHome; 
    copyIsland.display(std::cout);

    // 5. Test Assignment Operator
    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    Island thirdIsland("Empty Land", 2);
    thirdIsland = myHome; // Should trigger the 'Burn Down' and 'Rebuild' logic
    thirdIsland.display(std::cout);

    std::cout << "\n--- End of Tests ---" << std::endl;
    // Everything will be deleted automatically as they go out of scope
    return 0;
}