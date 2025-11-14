Here are **clean, professional, exam-ready C++ menu templates** — from **simple** to **pro-level reusable OOP menu**.
Pick the one you want, or I can integrate it with your **currency converter**.

---

# ✅ **1. Simple & Clean Menu (Beginner Friendly)**

```cpp
int choice;

cout << "=========================\n";
cout << "      MAIN  MENU\n";
cout << "=========================\n";
cout << "1. Convert Currency\n";
cout << "2. Show Rates\n";
cout << "3. About\n";
cout << "0. Exit\n";
cout << "=========================\n";
cout << "Enter choice: ";
cin >> choice;
```

---

# ✅ **2. Menu With Loop + Input Validation (Perfect for Projects)**

```cpp
#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n======= MAIN MENU =======\n";
        cout << "1. Convert Currency\n";
        cout << "2. Show Rates\n";
        cout << "3. About\n";
        cout << "0. Exit\n";
        cout << "=========================\n";
        cout << "Enter choice: ";

        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number: ";
        }

        switch (choice) {
            case 1:
                cout << ">> Conversion Selected\n";
                break;

            case 2:
                cout << ">> Rates Selected\n";
                break;

            case 3:
                cout << ">> About Section\n";
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
```

✔ Continuous
✔ Input validation
✔ Clean layout

---

# ✅ **3. PRO-LEVEL OOP Menu Class (Best for OOP Projects)**

Use this when teacher expects *"OOP structure"*.

```cpp
#include <iostream>
using namespace std;

class Menu {
public:
    void printMenu() {
        cout << "\n======= MAIN MENU =======\n";
        cout << "1. Convert Currency\n";
        cout << "2. Show Rates\n";
        cout << "3. About\n";
        cout << "0. Exit\n";
        cout << "=========================\n";
    }

    int getChoice() {
        int choice;
        cout << "Enter choice: ";

        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a valid number: ";
        }

        return choice;
    }

    void run() {
        int choice;
        do {
            printMenu();
            choice = getChoice();

            switch (choice) {
                case 1: cout << ">> Converting Currency...\n"; break;
                case 2: cout << ">> Showing Rates...\n"; break;
                case 3: cout << ">> About Program...\n"; break;
                case 0: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice!\n";
            }

        } while (choice != 0);
    }
};

int main() {
    Menu menu;
    menu.run();
}
```

✔ Perfect OOP separation
✔ Easy to integrate with converter class
✔ Great for exams
✔ Reusable

---

# ✅ **4. Fancy Menu With Clear Screen + Styling**

```cpp
#include <iostream>
using namespace std;

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showMenu() {
    cout << "-------------------------------------\n";
    cout << "        🌍 Currency Converter\n";
    cout << "-------------------------------------\n";
    cout << "1. Convert Currency\n";
    cout << "2. Show Exchange Rates\n";
    cout << "3. Settings\n";
    cout << "0. Exit\n";
    cout << "-------------------------------------\n";
}

int main() {
    int ch;

    while (true) {
        clear();
        showMenu();

        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 0) break;

        switch (ch) {
            case 1: cout << "Converting...\n"; break;
            case 2: cout << "Rates...\n"; break;
            case 3: cout << "Settings...\n"; break;
            default: cout << "Invalid!\n";
        }

        cin.ignore();
        cout << "Press Enter to continue...";
        cin.get();
    }

    return 0;
}
```

Looks very professional.

---

# ⭐ **If you want**, I can generate:

✅ Menu integrated with your **CurrencyConverter OOP design**
✅ Menu with **submenus (e.g., "Choose currency")**
✅ Color text (ANSI escape codes)
✅ A fully polished **MENU-driven project** (ready to submit)

Tell me what level you want!

Below is a **perfect, clean, industry-style file structure + build setup** for a small–medium **C++ CLI project** like your **OOP Currency Converter**.
This is EXACTLY how you should structure your project for exams and real work.

---

# 🎯 **FINAL OUTPUT YOU WILL GET**

* Clean and modular folder structure
* Proper headers + source files
* Makefile OR CMake (your choice)
* A recommended workflow for development
* Easy to expand and maintain

---

# ✅ **1. Ideal File Structure for Your OOP Project**

```
currency-converter/
│
├── include/
│   ├── RateTable.hpp
│   ├── CurrencyConverter.hpp
│   ├── Menu.hpp
│
├── src/
│   ├── RateTable.cpp
│   ├── CurrencyConverter.cpp
│   ├── Menu.cpp
│   ├── main.cpp
│
├── build/            // auto-created, compiled output
│   └── (object files + final exe)
│
├── Makefile          // OR CMakeLists.txt
│
└── README.md
```

---

# 📌 **2. What Goes Inside Each File**

---

## **include/RateTable.hpp**

```cpp
#ifndef RATETABLE_HPP
#define RATETABLE_HPP

#include <map>
#include <utility>

enum Currency { USD, EUR, INR, GBP };

class RateTable {
private:
    std::map<std::pair<Currency, Currency>, double> rates;

public:
    RateTable();
    double getRate(Currency from, Currency to);
};

#endif
```

---

## **src/RateTable.cpp**

```cpp
#include "../include/RateTable.hpp"

RateTable::RateTable() {
    rates[{USD, INR}] = 83.2;
    rates[{INR, USD}] = 0.012;
    rates[{USD, EUR}] = 0.94;
    rates[{EUR, USD}] = 1.06;
    rates[{INR, EUR}] = 0.011;
    rates[{EUR, INR}] = 91.8;
}

double RateTable::getRate(Currency from, Currency to) {
    return rates[{from, to}];
}
```

---

## **include/CurrencyConverter.hpp**

```cpp
#ifndef CURRENCYCONVERTER_HPP
#define CURRENCYCONVERTER_HPP

#include "RateTable.hpp"

class CurrencyConverter {
private:
    RateTable rateTable;

public:
    double convert(double amount, Currency from, Currency to);
};

#endif
```

---

## **src/CurrencyConverter.cpp**

```cpp
#include "../include/CurrencyConverter.hpp"

double CurrencyConverter::convert(double amount, Currency from, Currency to) {
    if (from == to) return amount;
    return amount * rateTable.getRate(from, to);
}
```

---

## **include/Menu.hpp**

```cpp
#ifndef MENU_HPP
#define MENU_HPP

#include "CurrencyConverter.hpp"

class Menu {
public:
    void start();
};

#endif
```

---

## **src/Menu.cpp**

```cpp
#include <iostream>
#include "../include/Menu.hpp"

using namespace std;

int chooseCurrency() {
    int c;
    cout << "1. USD\n2. EUR\n3. INR\n4. GBP\nChoose: ";
    cin >> c;
    return c - 1;
}

void Menu::start() {
    CurrencyConverter converter;

    cout << "=== Currency Converter ===\n";

    Currency from = (Currency) chooseCurrency();
    Currency to   = (Currency) chooseCurrency();

    double amt;
    cout << "Enter amount: ";
    cin >> amt;

    cout << "Converted: " << converter.convert(amt, from, to) << endl;
}
```

---

## **src/main.cpp**

```cpp
#include "../include/Menu.hpp"

int main() {
    Menu menu;
    menu.start();
    return 0;
}
```

---

# 🛠️ **3. Setting Up Your Build System**

You have two options:

---

# 🚀 **Option A: Simple Makefile (Best for 1-day projects)**

Create a file called **Makefile**:

```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = src/main.cpp src/Menu.cpp src/CurrencyConverter.cpp src/RateTable.cpp
OBJ = $(SRC:.cpp=.o)
OUT = build/currency_converter

all: $(OUT)

$(OUT): $(OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJ)

clean:
	rm -rf build *.o src/*.o

run: all
	./build/currency_converter
```

---

### ✔ Build:

```
make
```

### ✔ Run:

```
make run
```

---

# 🚀 **Option B: CMake (More professional, for resumes)**

Create **CMakeLists.txt**:

```cmake
cmake_minimum_required(VERSION 3.10)
project(CurrencyConverter)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(currency_converter ${SOURCES})
```

---

### ✔ Build using CMake:

```
mkdir build
cd build
cmake ..
make
```

### ✔ Run:

```
./currency_converter
```

---

# 👨‍💻 **4. Recommended Development Workflow**

### **1. Write class headers first**

(Plan the interfaces → `.hpp`)

### **2. Implement logic in `.cpp` files**

(Small functions, focused tasks)

### **3. Build frequently**

Use:

```
make
```

to catch errors early.

### **4. Run and test**

Use:

```
make run
```

### **5. Keep responsibilities separate**

* Menu handles input
* Converter handles math
* RateTable stores data

---

# 💡 Want something even better?

I can generate:

✅ Full **multi-level menu**
✅ **Colorful CLI UI**
Using ANSI escape codes
(looks professional in exams)

✅ A **logging system**
(for debugging or extra marks)

✅ A **unit-test setup**
(using Catch2)

Just say **"Add advanced version"** and I’ll build it for you.

