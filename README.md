# CPP Module 02

## 📝 Overview

This module delves into **Polymorphism**, **Operator Overloading**, and the **Orthodox Canonical Class Form** (OCF). It focuses on creating a robust **Fixed-Point Number** class to handle floating-point precision issues and applying it in a geometric context (Binary Space Partitioning).

## 📂 Project Structure

### ex00: My First Class in Orthodox Canonical Form
Introduction to the Fixed-point number class.
*   **Goal**: Create a class `Fixed` representing a fixed-point number.
*   **OCF Compliance**: Implements Default Constructor, Copy Constructor, Copy Assignment Operator, and Destructor.
*   **Storage**: Uses an `int` to store the fixed-point value and a static constant `frac_bits` (always 8) for the fractional bits.

### ex01: Towards a more useful fixed-point number class
Expanding the `Fixed` class functionality.
*   **Constructors**: Adds constructors for `int` and `float` inputs.
*   **Converters**: Implements `toInt()` and `toFloat()` to convert between fixed-point and native types.
*   **Stream Operator**: Overloads `<<` to allow printing `Fixed` objects directly to an output stream.

### ex02: Now we’re talking
Full-featured Fixed-point arithmetic and comparison.
*   **Comparison Operators**: `>`, `<`, `>=`, `<=`, `==`, `!=`.
*   **Arithmetic Operators**: `+`, `-`, `*`, `/`.
*   **Increment/Decrement**: Pre-increment (`++i`), Post-increment (`i++`), Pre-decrement (`--i`), Post-decrement (`i--`).
*   **Utilities**: Static member functions `min` and `max` for both non-const and const references.

### ex03: BSP
Binary Space Partitioning (BSP) application.
*   **Goal**: Determine if a 2D `Point` lies strictly inside a triangle defined by three vertices (`a`, `b`, `c`).
*   **`Point` Class**: Uses `Fixed` numbers for coordinates (`x`, `y`).
*   **Algorithm**: Uses the **Shoelace Formula** to calculate the area of the main triangle and sub-triangles formatted by the point and vertices.
    *   If `Area(ABC) == Area(ABP) + Area(ACP) + Area(BCP)`, the point is inside or on the edge.
    *   Strictly inside checks exclude points on the edges or vertices.

## 🛠️ Compilation & Usage

Each exercise has its own `Makefile`.

### ex00
```bash
cd ex00
make
./a.out
```

### ex01
```bash
cd ex01
make
./a.out
```

### ex02
```bash
cd ex02
make
./a.out
```

### ex03
```bash
cd ex03
make
./BSP
```

## 🧹 Housekeeping
To clean up object files and executables in any directory:
```bash
make clean
make fclean
```
