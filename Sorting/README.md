# Sorting Algorithms — C++ Interface Pattern

![C++](https://img.shields.io/badge/C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithms-Sorting-blue)

Five sorting algorithms implemented in C++ using an abstract interface pattern. Each algorithm is a concrete class derived from `iSorter`, demonstrating polymorphism, the Factory pattern, and manual memory management.

---

## Algorithms Implemented

| Algorithm | Average Case | Worst Case | Best Case |
|-----------|-------------|------------|-----------|
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Bubble Sort | O(n²) | O(n²) | O(n) |
| Insertion Sort | O(n²) | O(n²) | O(n) |
| Quick Sort | O(n log n) | O(n²) | O(n log n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |

---

## Technical Implementation

- **Abstract Interface** — `iSorter` defines a pure virtual `sort()` and `name()` contract that all sorters must implement
- **Polymorphism** — all sorters are accessed through `iSorter*` pointers, allowing uniform testing regardless of algorithm
- **Factory Pattern** — `CreateSorter(int)` instantiates the correct sorter by index, decoupling creation from usage
- **Dynamic Memory** — `MergeSorter` allocates temporary arrays during merge and cleans up with `delete[]`
- **No STL** — all sorting logic written from scratch using raw arrays and pointers

---

## Project Structure

```
Sorting/
├── iSorter.h       ← abstract interface + factory declaration
├── Sorter.h        ← concrete class declarations
├── Sorter.cpp      ← all algorithm implementations + factory
└── main.cpp        ← test harness with random float array
```

---

## How to Compile & Run

```bash
g++ Sorter.cpp main.cpp -o sorting
./sorting
```

Enter the number of elements when prompted. The program generates a random float array, runs each sorter, and confirms whether the result is sorted.

**Example output:**
```
Enter no of elements : 10000
Selection Sorter is sorted
Bubble Sorter is sorted
Insertion Sorter is sorted
Quick Sorter is sorted
Merge Sorter is sorted
```

---

## Key Design Decision

All five sorters are tested through the `iSorter*` interface — the test function has no knowledge of which algorithm it's running. Adding a new sorting algorithm requires only a new class deriving from `iSorter` and one line in `CreateSorter()` — no other code changes needed.

---

*Developed by Xenofon Gkioka*
