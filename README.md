# 📌 Orthodox Canonical Form (OCF) in C++

## 📜 Overview

The **Orthodox Canonical Form (OCF)** ensures that a C++ class correctly manages its resources, particularly when dealing with **dynamic memory**. A class following OCF must implement the following **four special member functions**:

---

## 🚀 Special Member Functions

### **1️⃣ Default Constructor**

```cpp
ClassName();
```

- Initializes objects when no arguments are provided.

### **2️⃣ Copy Constructor**

```cpp
ClassName(const ClassName& other);
```

- Creates a **new object** as a copy of an existing one.
- Ensures **deep copying** if the class manages dynamic memory.
- The **default copy constructor** performs a **shallow copy**.

### **3️⃣ Copy Assignment Operator**

```cpp
ClassName& operator=(const ClassName& other);
```

- Assigns one existing object to another, ensuring **proper resource management**.
- Handles **self-assignment** and **deep copying** if needed.

### **4️⃣ Destructor**

```cpp
~ClassName();
```

- Cleans up allocated resources to **prevent memory leaks**.

---

## 💡 **Example: Implementing OCF**

```cpp
#include <iostream>
#include <cstring>

class MyClass {
private:
    char* data;

public:
    // 1️⃣ Default Constructor
    MyClass() : data(nullptr) {
        std::cout << "Default constructor called.\n";
    }

    // 2️⃣ Copy Constructor (Deep Copy)
    MyClass(const MyClass& other) {
        std::cout << "Copy constructor called.\n";
        if (other.data) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }

    // 3️⃣ Copy Assignment Operator (Deep Copy)
    MyClass& operator=(const MyClass& other) {
        std::cout << "Copy assignment operator called.\n";
        if (this != &other) {  // Prevent self-assignment
            delete[] data;  // Clean up existing resource
            if (other.data) {
                data = new char[strlen(other.data) + 1];
                strcpy(data, other.data);
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    // 4️⃣ Destructor
    ~MyClass() {
        std::cout << "Destructor called.\n";
        delete[] data;
    }

    // Extra function to set data
    void setData(const char* newData) {
        delete[] data;
        data = new char[strlen(newData) + 1];
        strcpy(data, newData);
    }

    // Extra function to print data
    void print() const {
        std::cout << "Data: " << (data ? data : "Empty") << std::endl;
    }
};

int main() {
    MyClass obj1;
    obj1.setData("Hello");

    MyClass obj2 = obj1; // Calls copy constructor
    obj2.print();

    MyClass obj3;
    obj3 = obj1; // Calls copy assignment operator
    obj3.print();

    return 0;
}
```

---

# 🎯 **Operator Overloading in C++**

## 🚀 What is Operator Overloading?

Operator overloading allows you to **redefine the behavior of operators** (`+`, `-`, `=`, `==`, etc.) for user-defined types (classes/structs).

### **Example: Overloading `+` Operator**

```cpp
#include <iostream>

class Vector2D {
public:
    int x, y;

    Vector2D(int a, int b) : x(a), y(b) {}

    // Overloading + operator
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Vector2D v1(3, 4), v2(1, 2);
    Vector2D v3 = v1 + v2;  // Uses overloaded +
    
    v3.display(); // Output: (4, 6)
}
```
---

## 🎯 **Precision vs. Accuracy**

- **Precision**: How detailed or consistent a value is when repeatedly measured.
- **Accuracy**: How close a value is to the true or expected value.

📌 **Example**:
- A floating-point number may be **precise** (many decimal places) but **not accurate** (rounding errors).
- A fixed-point number may be **accurate** (exact representation) but **less precise** (limited decimal places).

---

# 🔢 **Integer, Fixed-Point, and Floating-Point Numbers**

| Type           | Can Store Decimals? | Precision            | Accuracy         | Speed     | Common Use           |
| -------------- | ------------------- | -------------------- | ---------------- | --------- | -------------------- |
| Integer        | ❌ No                | 🔹 Exact             | ✅ High           | ⚡ Fast    | Counting, indexing   |
| Fixed-Point    | ✅ Yes (Fixed #)     | ✅ High               | ✅ High           | ⚡ Fast    | Finance, currency    |
| Floating-Point | ✅ Yes (Variable)    | ❌ May lose precision | ❌ May lose accuracy | 🔢 Slower | Scientific computing |

---

## 🔹 Key Differences in Precision:

| Feature                | Floating-Point                                  | Fixed-Point                                       |
|------------------------|-----------------------------------------------|--------------------------------------------------|
| Representation         | Approximation of real numbers (scientific notation) | Exact representation of fixed-point numbers |
| Precision             | Limited to a few significant digits (7-16)    | High precision based on frac_bits              |
| Arithmetic Operations | Rounding errors accumulate                     | Exact arithmetic with no rounding errors       |
| Use Cases            | Ideal for scientific calculations but not for money, counters, or hardware | Ideal for embedded systems, financial applications, and hardware without floating-point support |

---

## Floating-Point Numbers

Floating-point numbers are stored in a **sign + exponent + mantissa** format.

✅ Computers use **binary scientific notation**.

❌ Not all decimal numbers can be exactly stored in binary, causing **rounding errors**.

📜 **IEEE 754** helps standardize floating-point representation across computers.

---

## Fixed-Point Numbers

### Example Calculation:

- **53 (decimal) → 110101 (binary)**
- **53 / 2 = 26.5 → 110101.2 (binary representation after division)**

### Shifting the Bit Pattern:

- **Shifting a fixed-point number right** divides by 2.
- **Shifting a fixed-point number left** multiplies by 2.

### Fixed-Point Representation:

To define a fixed-point number, two parameters are needed:

1️⃣ **Width of the number representation.**
2️⃣ **Binary point position within the number.**

### Notation: `fixed<w,b>`

- `w`: Width of the number.
- `b`: Position of the binary point (from least significant bit).

Example: `fixed<8,3>` with representation **00010.110** means:

- `110` is behind the binary point.
- **Binary representation**: `00010.110`. 

