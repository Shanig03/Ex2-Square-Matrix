# Matrix Operators Project

## Overview

This project implements a custom `SquareMat` class for square matrices in C++, under the `squareMatrix` namespace. It supports a wide variety of operator overloads, including arithmetic, comparison, scalar operations, and advanced features like matrix exponentiation, transpose, and determinant.

The implementation emphasizes:
- Manual memory management (no STL containers used)
- Deep copy and move semantics
- Clean operator overloading for intuitive mathematical syntax
- Thorough testing with `Doctest`
- Memory safety checked with `valgrind`

---

## Features

### Supported Operators

| Operator       | Description                                                      |
|----------------|------------------------------------------------------------------|
| `+`, `-`, `*`, `/` | Element-wise matrix addition, subtraction, multiplication, and scalar division |
| `+=`, `-=`, `*=` | Compound arithmetic assignments                                 |
| `==`, `!=`, `<`, `<=`, `>`, `>=` | Matrix comparisons (by sum of all elements)                 |
| `[]`, `()`     | Element access (1D or 2D style)                                   |
| `++`, `--`     | Element-wise increment and decrement (prefix and postfix)        |
| `!mat`         | Determinant of the matrix                                         |
| `~mat`         | Transpose of the matrix                                           |
| `mat ^ n`      | Matrix raised to power `n` (only integers, including 0)          |
| `mat % n`      | Matrix modulo scalar `n` (element-wise)                          |
| `<<`           | Stream output (for `std::cout`, etc.)                            |

---

## File Structure

- `SquareMat.hpp` – Class declaration
- `SquareMat.cpp` – Class implementation
- `Main.cpp` – Example usage
- `Tests.cpp` – Unit tests using Doctest
- `doctest.h` – Header-only testing library
- `makefile` – Build and run instructions

---

## How to Run

Ensure you're in the project root directory and have `clang++` installed.

### Build Main Program
```bash
make Main
```
#### Than run the Main Program:
```bash
./Main
```

### Memory Check with Valgrind
```bash
make valgrind
```
### Clean Build Files
```bash
make clean
```
## Usage example

```bash
SquareMat a(2);
a[0][0] = 1; a[0][1] = 3;
a[1][0] = 2; a[1][1] = 4;

SquareMat b = ~a;         // Transpose
SquareMat c = a * b;      // Matrix multiplication
SquareMat d = c / 2;      // Scalar division
bool isEqual = (a == b);  // Comparison
double det = !a;          // Determinant
```
