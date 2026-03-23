// Sorter Hierarchy - Implementation
// Sorter.cpp

#include "Sorter.h"

// Selection Sorter
void SelectionSorter::sort(float* a, int n) {
    int i, j, min_idx;
    float temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;
        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

const char* SelectionSorter::name() const {
    return "Selection Sorter";
}

// Bubble Sorter
void BubbleSorter::sort(float* a, int n) {
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

const char* BubbleSorter::name() const {
    return "Bubble Sorter";
}

// Insertion Sorter
void InsertionSorter::sort(float* a, int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

const char* InsertionSorter::name() const {
    return "Insertion Sorter";
}

// Quick Sorter
void QuickSorter::sort(float* a, int n) {
    quickSort(a, 0, n - 1);
}

const char* QuickSorter::name() const {
    return "Quick Sorter";
}

void QuickSorter::quickSort(float* a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int QuickSorter::partition(float* a, int low, int high) {
    float pivot = a[high];
    int i = (low - 1);
    float temp;
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return (i + 1);
}

// Merge Sorter
void MergeSorter::sort(float* a, int n) {
    mergeSort(a, 0, n - 1);
}

const char* MergeSorter::name() const {
    return "Merge Sorter";
}

void MergeSorter::mergeSort(float* a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void MergeSorter::merge(float* a, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    float* L = new float[n1];
    float* R = new float[n2];

    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { a[k] = L[i]; i++; }
        else { a[k] = R[j]; j++; }
        k++;
    }

    while (i < n1) { a[k] = L[i]; i++; k++; }
    while (j < n2) { a[k] = R[j]; j++; k++; }

    delete[] L;
    delete[] R;
}

iSorter* CreateSorter(int i) {
    switch (i) {
        case 0: return new SelectionSorter();
        case 1: return new BubbleSorter();
        case 2: return new InsertionSorter();
        case 3: return new QuickSorter();
        case 4: return new MergeSorter();
        default: return nullptr;
    }
}

int noOfSorters() {
    return 5;
}
