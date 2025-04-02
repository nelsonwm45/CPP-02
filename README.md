# 📌 Orthodox Canonical Form (OCF) in C++

## 📜 Rules
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
## ⚠️ **Shallow Copy vs. Deep Copy**

### **Shallow Copy (🚨 Dangerous)**
- Copies only the **memory address** instead of duplicating the actual data.
- If two objects share the **same memory location**, modifying one affects the other.
- If the original object is deleted, the copied object **may end up with a dangling pointer**, leading to **undefined behavior**.

#### **Example of Shallow Copy Issue**
```cpp
#include <iostream>

class Shallow {
public:
    int* data;

    Shallow(int val) {
        data = new int(val); // Allocate memory
    }

    // Default copy constructor (shallow copy)
    Shallow(const Shallow& other) = default;

    ~Shallow() {
        delete data; // This will cause problems if multiple objects share the same memory
    }
};

int main() {
    Shallow obj1(10);
    Shallow obj2 = obj1; // Shallow copy (both obj1 and obj2 point to the same memory)

    std::cout << "obj1 data: " << *(obj1.data) << "\n";
    std::cout << "obj2 data: " << *(obj2.data) << "\n";

    delete obj1.data; // Now obj2.data is a dangling pointer!

    return 0;
}
```

### **Deep Copy (✅ Safe)**
To **fix shallow copy issues**, we need to implement a **deep copy**, where a new memory block is allocated for each object.

#### **Example of Deep Copy Implementation**
```cpp
class DeepCopy {
private:
    int* data;

public:
    // Constructor
    DeepCopy(int val) {
        data = new int(val);
    }

    // Copy Constructor (Deep Copy)
    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data); // Allocate new memory and copy value
    }

    ~DeepCopy() {
        delete data;
    }
};
```

---
## 📌 **Difference Between Copy Constructor & Copy Assignment Operator**

| Code | Constructor/Operator Called |
|------|-----------------------------|
| `MyClass obj2 = obj1;` | **Copy Constructor** |
| `MyClass obj3;` <br> `obj3 = obj1;` | **Copy Assignment Operator** |

### **🔹 Copy Constructor**
📌 **Called when declaring and initializing an object at the same time.**

#### **Example**
```cpp
MyClass obj1;       // Default Constructor
MyClass obj2 = obj1; // 📌 Copy Constructor is called
```
💡 `obj2` is created **using `obj1`**, so the **copy constructor** is used.

---
### **🔹 Copy Assignment Operator (`operator=`)**
📌 **Called when an already declared object is assigned a value from another object.**

#### **Example**
```cpp
MyClass obj1;  // Default Constructor
MyClass obj2;  // Default Constructor

obj2 = obj1;   // 📌 Copy Assignment Operator is called
```
💡 `obj2` was **already created**, so the **copy assignment operator** is used to copy `obj1`'s data.

