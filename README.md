# Square Matrix Project

## Overview

Email: shanig7531@gmail.com

This project implements a custom `SquareMat` class for square matrices in C++, under the `squareMatrix` namespace. It supports a wide variety of operator overloads, including arithmetic, comparison, scalar operations, and advanced features like matrix exponentiation, transpose, and determinant.


It doesn't use vectors or other STL containers—just raw pointers and manual memory management. All features are tested with Doctest, and memory is checked with Valgrind to make sure there are no leaks.

You can build, run, test, and check everything using make.

The implementation emphasizes:
- Manual memory management (no STL containers used)
- Clean operator overloading for intuitive mathematical syntax
- Thorough testing with `Doctest`
- Memory safety checked with `valgrind`

---

## Features

### Supported Operators

| Operator       | Description                                                      |
|----------------|------------------------------------------------------------------|
| `+`, `-`, `%`, `*` , `/` | Element-wise matrix addition, subtraction, multiplication, scalar multiplication, and scalar division |
| `mat1*mat2` | Matrix multiplication |
| `-mat` | Unary minus |
| `+=`, `-=`, `*=`, `/=`, `%=` | Compound arithmetic assignments                                 |
| `==`, `!=`, `<`, `<=`, `>`, `>=` | Matrix comparisons (by sum of all elements)                 |
| `[]`     | Element access                                                       |
| `++`, `--`     | Element-wise increment and decrement (prefix and postfix)        |
| `!mat`         | Determinant of the matrix                                         |
| `~mat`         | Transpose of the matrix                                           |
| `mat ^ n`      | Matrix raised to power `n`      |
| `mat % n`      | Matrix modulo scalar `n` (element-wise)                          |
| `<<`           | Stream output                        |

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

### Test running
```bash
make test
```
### Clean Build Files
```bash
make clean
```

