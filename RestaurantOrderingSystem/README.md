# C++ Restaurant Ordering System

A modular and extensible C++ application designed for managing restaurant menus, customer orders, and automated bill generation. This project showcases Object-Oriented Programming (OOP) principles, including inheritance, polymorphism, and file I/O.

## 🚀 Features

- **Hierarchical Menu Management:** A flexible interactive CLI menu system for easy navigation.
- **Food & Drink Specialization:** Distinct classes for food and drinks, supporting item-specific features (e.g., sizes for drinks, customizations for food).
- **Automated Bill Calculation:** Dynamically tracks ordered items and calculates taxes and totals with high precision.
- **Data Persistence:** Seamlessly loads menu items from CSV data files.
- **Robust Input Validation:** Ensures a smooth user experience with comprehensive input handling.

## 🏗️ Architecture

The system is built on a solid OOP foundation with the following core components:

- **`Billable` (Abstract Base Class):** Defines the common interface for all billable items, ensuring consistent behavior for printing and pricing.
- **`Food` & `Drink`:** Specialized subclasses that extend `Billable` to handle unique attributes and logic for different menu categories.
- **`Menu` & `MenuItem`:** Power the interactive user interface, providing a reusable way to create nested command-line menus.
- **`Ordering`:** The central engine that orchestrates the entire process—from loading data to managing the customer's current bill.
- **`Utils`:** A collection of helper functions for string manipulation and input handling.

## 🛠️ Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`, `clang++`)
- Standard C++ Library

### Compilation

Clone the repository and compile the source files using your preferred compiler:

```bash
g++ *.cpp -o restaurant_system
```

### Usage

Run the executable to start the application:

```bash
./restaurant_system
```

The system will load data from `drinks.csv` and `foods.csv` and present the main menu for ordering.

## 📂 Project Structure

- `Billable.h/cpp`: Base class for orderable items.
- `Food.h/cpp`: Specialized class for food products.
- `Drink.h/cpp`: Specialized class for beverages.
- `Ordering.h/cpp`: Main logic for the ordering system.
- `Menu.h/cpp`: CLI menu implementation.
- `Utils.h/cpp`: Utility and helper functions.
- `constants.h`: Global project constants.
- `main.cpp`: Application entry point.
- `*.csv`: Sample data files for menu items.

## 📄 License

This project is open-source and available for educational purposes.
