#LexiStore Engine 🚀

A high-performance, memory-managed Key-Value database engine built from scratch in C++. 

## 🛠 Technical Highlights
This project demonstrates advanced C++ concepts required for system-level programming and acing Object-Oriented Programming exams:
    
- **Manual Memory Management:** Uses raw pointers and `new[]`/`delete[]` to manage dynamic strings and arrays.
- **The Rule of Three:** Implements custom Destructors, Copy Constructors, and Copy Assignment Operators for all resource-owning classes.
- **Resizing Logic:** A custom `operator+=` that handles dynamic array reallocation (The "Resizing Pattern").
- **Composition Architecture:** A `KVStore` container that manages a collection of `Entry` objects.
- **Robust Input Validation:** Prevents program crashes by sanitizing standard input streams.

## 📂 Project Structure
- `Entry`: Handles individual Key-Value pairs with deep-copy string logic.
- `KVStore`: The database controller managing a dynamic collection of Entries.
- `Utils`: Helper functions for safe user interaction.

## 🚀 Why this exists
20 This engine was built to master the "under-the-hood" mechanics of C++, specifically focusing on deep copying vs shallow copying and the management of
dynamic memory arrays without using standard library containers like `std::string` or `std::vector`.

---
