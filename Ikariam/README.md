# Ikariam (C++)

![C++](https://img.shields.io/badge/C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)
![Simulation](https://img.shields.io/badge/Game-Simulation-green)

A modular building simulation and strategy engine written in C++, inspired by the popular browser game Ikariam. This project demonstrates clean architectural design using Object-Oriented Programming (OOP) principles.

## 🚀 Game Features

- **Island Management:** Efficient data structures to handle island resources and state.
- **Building System:** An extensible hierarchy of buildings (Academies, etc.) using inheritance and polymorphism.
- **Resource Simulation:** Dynamic calculation of resource generation and construction progress over time.
- **Modular Design:** Separate header and implementation files for high maintainability and scalability.

## 🛠️ Technical Implementation

- **Abstract Base Class** — `Building` uses pure virtual `print()` and `clone()` enforcing the interface across all derived types
- **Rule of Three** — copy constructor, assignment operator, and destructor all implemented for safe deep copy of dynamic memory
- **Polymorphism** — `Island` stores `Building*` pointers, calling the correct derived class behaviour at runtime
- **Clone Pattern** — buildings are cloned onto the heap when added to an island, preventing dangling pointer issues
- **Dynamic Memory** — manual memory management with `new`/`delete`, no STL containers

## ⚙️ How to Compile

Navigate to the root directory and use a C++ compiler (e.g., g++):

```bash
g++ -Iinclude src/*.cpp -o ikariam
./ikariam
```

---
*Developed by Xenofon Gkioka*
