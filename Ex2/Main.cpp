// Email: shanig7531@gmail.com

#include "SquareMat.hpp"
#include <iostream>

using namespace squareMatrix;

int main() {
    
    std::cout << "===== Initializing 2x2 matrices =====\n";
    SquareMat A(2), B(2);
    A[0][0] = 1; 
    A[0][1] = 3;
    A[1][0] = 2; 
    A[1][1] = 4;

    B[0][0] = 0; 
    B[0][1] = 3;
    B[1][0] = 2; 
    B[1][1] = 4;


    std::cout << "Matrix A:\n" << A << "\n";
    std::cout << "Matrix B:\n" << B << "\n";

    std::cout << "Trying to access the matrix with index out of range:\n";
    try {
        A[8][7] = 9;   
    }
    catch(const std::out_of_range& e){
        std::cerr << e.what() << "\n\n";
    } 

    std::cout << "===== Arithmetic Operations =====\n";
    std::cout << "A + B:\n" << (A + B) << "\n";
    std::cout << "A - B:\n" << (A - B) << "\n";
    std::cout << "-A:\n" << (-A) << "\n";

    std::cout << "A * B:\n" << (A * B) << "\n";
    std::cout << "A * 2:\n" << (A * 2) << "\n";
    std::cout << "3 * B:\n" << (3 * B) << "\n";

    std::cout << "A / 2:\n" << (A / 2) << "\n";
    std::cout << "A % B:\n" << (A % B) << "\n";
    std::cout << "A % 2:\n" << (A % 2) << "\n";

    std::cout << "===== Compound Assignment Operators =====\n";
    SquareMat C = A;
    C += B;
    std::cout << "C = A AND C += B:\n" << C << "\n";

    C -= B;
    std::cout << "C -= B:\n" << C << "\n";

    C *= B;
    std::cout << "C *= B:\n" << C << "\n";

    C *= 3;
    std::cout << "C *= 3:\n" << C << "\n";

    C /= 2;
    std::cout << "C /= 2:\n" << C << "\n";

    C %= B;
    std::cout << "C %= B:\n" << C << "\n";

    C %= 3;
    std::cout << "C %= 3:\n" << C << "\n";

    std::cout << "===== Increment / Decrement Operators =====\n";
    std::cout << "C++:\n" << C++ << "\n";
    std::cout << "After C++:\n" << C << "\n";
    std::cout << "++C:\n" << ++C << "\n";

    std::cout << "C--:\n" << C-- << "\n";
    std::cout << "After C--:\n" << C << "\n";
    std::cout << "--C:\n" << --C << "\n";

    std::cout << "===== Power Operator =====\n";
    std::cout << "A ^ 2:\n" << (A ^ 2) << "\n";
    std::cout << "A ^ 0 (Identity matrix):\n" << (A ^ 0) << "\n";

    std::cout << "===== Comparison Operators =====\n";
    SquareMat D = A;
    std::cout << "D (copy of A):\n" << D << "\n";

    std::cout << "A == D: " << (A == D) << "\n";
    std::cout << "A != B: " << (A != B) << "\n";
    std::cout << "A > B: " << (A > B) << "\n";
    std::cout << "A < B: " << (A < B) << "\n";
    std::cout << "A >= D: " << (A >= D) << "\n";
    std::cout << "A <= D: " << (A <= D) << "\n";

    std::cout << "===== Transpose and Determinant =====\n";
    std::cout << "~A (transpose):\n" << ~A << "\n";

    SquareMat E(3);
    E[0][0] = -2; 
    E[0][1] = 2; 
    E[0][2] = -3;
    E[1][0] = -1; 
    E[1][1] = 1; 
    E[1][2] = 3;
    E[2][0] = 2;  
    E[2][1] = 0; 
    E[2][2] = -1;

    std::cout << "Matrix E:\n" << E << "\n";
    std::cout << "!E (determinant): " << !E << "\n";

    return 0;
}
