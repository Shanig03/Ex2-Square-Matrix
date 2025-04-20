#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>
#include <stdexcept>

namespace squareMatrix {

    class SquareMat {

        private:
        int n;
        double** matrix;
        

        public:
        SquareMat(int matrixSize); // Constractor
        SquareMat(const SquareMat& other); // Copy constractor

        ~SquareMat(); // Distractor

        // חיבור וחיסור בין מטריצות
        SquareMat operator+(const SquareMat& other) const; // mat1 + mat2
        SquareMat operator-(const SquareMat& other) const; // mat1 - mat2

        // אופרטור מינוס אונארי
        SquareMat operator-() const;

        // כפל מטריצות
        SquareMat operator*(const SquareMat& other) const;

        
        SquareMat operator*(int scalar) const; // Multiply from the right
        friend SquareMat operator*(int scalar, const SquareMat& matrix); // Multiply from the left
        SquareMat operator/(int scalar) const;


        // כפל איברי בין שתי מטריצות (%)
        SquareMat operator%(const SquareMat& other) const;

        // מודולו עם סקלר (%)
        SquareMat operator%(int scalar) const;

        // חזקה של מטריצה
        SquareMat operator^(int power) const;

        // הגדלה והקטנה (pre/post increment/decrement)
        SquareMat& operator++();     // ++mat
        SquareMat operator++(int);   // mat++
        SquareMat& operator--();     // --mat
        SquareMat operator--(int);   // mat--

        // טרנספוז (transpose)
        SquareMat operator~() const;

        // גישה לאיברים
        double* operator[](int row);
        const double* operator[](int row) const;


        // השוואות ==, != לפי סכום האיברים
        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;

        // השוואות סדר (מבוסס על סכום האיברים)
        bool operator<(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;


        // דטרמיננטה (!mat)
        double operator!() const;
    
        // אופרטורים משולבים += -= *= /= %=
        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);

        SquareMat& operator*=(const SquareMat& other); // כפל מטריצות
        SquareMat& operator*=(int scalar);

        SquareMat& operator/=(int scalar);

        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator%=(int scalar);

        // הדפסה
        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);


        //copy assignment operator
        SquareMat& operator=(const SquareMat& other);
        SquareMat& operator=(SquareMat&& other) noexcept;

        private:
        double matrixSum(const SquareMat& mat) const;

    };

}

#endif