// Test Main for the iSorter Interface
// Test_Main.cpp

#include <iostream>
#include <ctime>
#include "iSorter.h"

void populate(float* a, int n) {
    srand(time(nullptr));
    float f = 1.0f / RAND_MAX;
    for (int i = 0; i < n; i++)
        a[i] = rand() * f;
}

void test(iSorter* sorter, float* a, int n) {
    sorter->sort(a, n);
    bool sorted = true;
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i+1]) sorted = false;
    if (sorted)
        std::cout << sorter->name()
        << " is sorted" << std::endl;
    else
        std::cout << sorter->name()
        << " is not sorted" << std::endl;
}

int main() {
    int n;
    std::cout << "Enter no of elements : ";
    std::cin >> n;
    float* array = new float[n];

    for (int i = 0; i < noOfSorters(); i++) {
        iSorter* sorter = CreateSorter(i);
        populate(array, n);
        test(sorter, array, n);
        delete sorter;
    }

    delete [] array;
}