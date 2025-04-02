# CPP-02

## Orthodox Canonical Form

New rules was made :
    Each class must be designed in Orthodox Canonical Form
        A class correctly manages its resources, particularly when dealing with dynamic memory
        A class in OCF must implement these FOUR SPECIAL MEMBER FUNCTION :
        1. Default Constructor (ClassName())
            > Initializes objects when no arguments are provided.
        
        2. Copy constructor (ClassName(const ClassName& other))
            > Creates a new object as a copy of an existing one.
            > Ensures deep copying if the class manages dynamic memory.
        
        3. Copy assignment operator (ClassName& operator=(const ClassName& other))
            > Assigns one existing object to another, ensuring proper resource management.
            > Handles self-assignment and deep copying if needed.
        
        4. Destructor (~ClassName())
            > Cleans up any allocated resources to prevent memory leaks.
    
**Basic Code Example**
```
#include <iostream>
#include <cstring>

class MyClass {
private:
    char* data;

public:
    // 1. Default constructor
    MyClass() : data(nullptr) {
        std::cout << "Default constructor called.\n";
    }

    // 2. Copy constructor (deep copy)
    MyClass(const MyClass& other) {
        std::cout << "Copy constructor called.\n";
        if (other.data) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }

    // 3. Copy assignment operator (deep copy)
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

    // 4. Destructor
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

**Shallow Copy**
    Copies only memory address(pointers) rather than duplicating the actual data:
        If the original object and the copied object share the same memory location, modifying one affects the other.
        If the original object is deleted, the copied object may end up with a dangling pointer, leading to undefined behavior.
    
    Problems with Shallow Copy:
        Both objects share the same memory, so deleting one object affects the other.
        Leads to dangling pointers and double deletion errors.

```
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