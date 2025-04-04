# 📌 Orthodox Canonical Form (OCF) in C++

---

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

# 🔢 **Integer, Fixed-Point, and Floating-Point Numbers**

| Type           | Can Store Decimals? | Precision            | Accuracy         | Speed     | Common Use           |
| -------------- | ------------------- | -------------------- | ---------------- | --------- | -------------------- |
| Integer        | ❌ No                | 🔹 Exact             | ✅ High           | ⚡ Fast    | Counting, indexing   |
| Fixed-Point    | ✅ Yes (Fixed #)     | ✅ High               | ✅ High           | ⚡ Fast    | Finance, currency    |
| Floating-Point | ✅ Yes (Variable)    | ❌ May lose precision | ❌ May lose accuracy | 🔢 Slower | Scientific computing |

---

# 🧠 **Precision vs. Accuracy**

- **Precision**: How detailed or consistent a value is when repeatedly measured.
- **Accuracy**: How close a value is to the true or expected value.

📌 **Example**:
- A floating-point number may be **precise** (many decimal places) but **not accurate** (rounding errors).
- A fixed-point number may be **accurate** (exact representation) but **less precise** (limited decimal places).

---

# ⚡ **Floating-Point & Fixed-Point Numbers**

### 🔹 **Floating-Point Representation (IEEE 754)**

| Format           | Sign Bit | Exponent Bits | Mantissa Bits |
|-----------------|---------|--------------|--------------|
| Single Precision (32-bit) | 1 | 8 | 23 |
| Double Precision (64-bit) | 1 | 11 | 52 |

Example: **6.75 in IEEE 754 format**
1. Convert `6.75` to binary → `110.11`
- **Integer:** 6 in binary is 110
- **Fractional Bits:** 0.75
- Multiply 0.75 by 2 → 1.5 (take the 1).
- Multiply 0.5 by 2 → 1.0 (take the 1).
- So 0.75 becomes .11 in binary.
- `6.75` to binary → `110.11`

2. Normalize `110.11` → `1.1011 × 2^2`
- **Mantissa** : 1.1011 (ignoring the leading 1).
- **Exponent** : 2 because the decimal point moved 2 places to the left.

3. Store as `Sign | Exponent (biased) | Mantissa`
- **Sign Bit** : 0
- **Exponenet Bit** : 2 + 127 = 129; 10000001(binary)
- **Mantissa** : Ignore leading 1; and store rest (10110000000000000000000).

---
## Fixed-Point Numbers

### Example Calculation:

- **53 (decimal) → 110101 (binary)**
- **53 / 2 = 26.5 → 110101.2 (binary representation after division)**

### Shifting the Bit Pattern:

- **Shifting a fixed-point number right** divides by 2.
- **Shifting a fixed-point number left** multiplies by 2.

### 🔹 **Fixed-Point Representation**

Fixed-point numbers have a **fixed number of decimal places** and are defined as `fixed<w,b>`:

- `w`: Total bit-width
- `b`: Binary point position

Example: `fixed<8,3>` → **Binary representation: `00010.110`**

---

