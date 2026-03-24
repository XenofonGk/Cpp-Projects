#include <iostream>
#include "Utils.h"
using namespace std;

namespace LexiStore {
    void clearBuffer() {
        while (cin.get() != '\n'); // Clear the input buffer
    }

    int getInt(int min, int max, const char* prompt) {
        int val;
        bool ok = false;
        if (prompt) cout << prompt;
        do {
            if (!(cin >> val) || val < min || val > max) {
                cout << "Invalid Input. Please enter a value between " << min << " and " << max << ": ";
                 cin.clear();
                clearBuffer();
           } else {
                ok = true;
                 clearBuffer();
            }
        } while (!ok);
        return val;
     }
}