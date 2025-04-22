// Email: shanig7531@gmail.com

#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>
#include <stdexcept>

namespace squareMatrix {

    class SquareMat {

        private:
        int n; // Matrix size
        double** matrix;
        
        public:
        SquareMat(int matrixSize); // Constructor
        SquareMat(const SquareMat& other); // Copy constructor

        ~SquareMat(); // Destructor

        // Addition and subtraction between matrices
        SquareMat operator+(const SquareMat& other) const; // mat1 + mat2
        SquareMat operator-(const SquareMat& other) const; // mat1 - mat2

        // Unary minus operator
        SquareMat operator-() const;

        // Matrix multiplication
        SquareMat operator*(const SquareMat& other) const;

        SquareMat operator*(int scalar) const; // Multiply from the right
        friend SquareMat operator*(int scalar, const SquareMat& matrix); // Multiply from the left
        SquareMat operator/(int scalar) const;

        // Element-wise multiplication between two matrices
        SquareMat operator%(const SquareMat& other) const;

        // Modulo with scalar
        SquareMat operator%(int scalar) const;

        // Power of matrix
        SquareMat operator^(int power) const;

        // Increment and decrement (pre/post)
        SquareMat& operator++(); // ++mat
        SquareMat operator++(int); // mat++
        SquareMat& operator--(); // --mat
        SquareMat operator--(int); // mat--

        // Transpose
        SquareMat operator~() const;

        // Element access
        double* operator[](int row);
        const double* operator[](int row) const;

        // Equality comparisons ==, != based on sum of elements
        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;

        // Relational comparisons based on sum of elements
        bool operator<(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;

        // Determinant (!mat)
        double operator!() const;
    
        // Compound operators += -= *= /= %=
        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);

        SquareMat& operator*=(const SquareMat& other); // Matrix multiplication
        SquareMat& operator*=(int scalar);

        SquareMat& operator/=(int scalar);

        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator%=(int scalar);

        // Output stream operator
        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

        // Copy and move assignment operators
        SquareMat& operator=(const SquareMat& other);
        SquareMat& operator=(SquareMat&& other) noexcept;

        private:

        // Helper function to calculate the sum of the matrix
        double matrixSum(const SquareMat& mat) const;

    };

}

#endif
