// Sorter Concrete Classes
// Sorter.h

#ifndef SORTER_H
#define SORTER_H

#include "iSorter.h"

class SelectionSorter : public iSorter {
public:
    void sort(float* a, int n);
    const char* name() const;
};

class BubbleSorter : public iSorter {
public:
    void sort(float* a, int n);
    const char* name() const;
};

class InsertionSorter : public iSorter {
public:
    void sort(float* a, int n);
    const char* name() const;
};

class QuickSorter : public iSorter {
public:
    void sort(float* a, int n);
    const char* name() const;
private:
    void quickSort(float* a, int low, int high);
    int partition(float* a, int low, int high);
};

class MergeSorter : public iSorter {
public:
    void sort(float* a, int n);
    const char* name() const;
private:
    void mergeSort(float* a, int l, int r);
    void merge(float* a, int l, int m, int r);
};

iSorter* CreateSorter(int i);
int noOfSorters();

#endif
