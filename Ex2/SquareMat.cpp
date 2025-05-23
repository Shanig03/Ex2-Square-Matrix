// Email: shanig7531@gmail.com

#include "SquareMat.hpp"
#include <cmath>

namespace squareMatrix {

    // Constructor
    SquareMat::SquareMat(int matrixSize){
        // Check that the matrix size is valid
        if (matrixSize < 0){
            throw std::invalid_argument("Size of matrix must be greater than 0.");
        }

        this->n = matrixSize;
        matrix = new double*[matrixSize];
        for (int i = 0; i < matrixSize; ++i) {
            matrix[i] = new double[matrixSize]{0};
        }

    }

    // Copy constructor
    SquareMat::SquareMat(const SquareMat& other) {
        // Allocate memory for the new matrix
        this->n = other.n;
        this->matrix = new double*[this->n];

        for (int i = 0; i < this->n; ++i) {
            this->matrix[i] = new double[this->n];

            // Copy each element from the other matrix
            for (int j = 0; j < this->n; ++j) {
                this->matrix[i][j] = other.matrix[i][j];
            }
        }
    }


    // Destructor
    SquareMat::~SquareMat(){
        // Free each dynamically allocated "matrix line"
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i]; // Free the row memory
        }

        // Free the array of pointers
        delete[] matrix;

        // Set the matrix pointer to nullptr to prevent dangling pointer
        matrix = nullptr;
    }


    // Matrix addition
    SquareMat SquareMat::operator+(const SquareMat& other) const{
        // Ensure the matrices are of the same size
        if (this->n != other.n) {
            throw std::invalid_argument("Matrices must have the same size for addition.");
        }
        // Create a new matrix to store the result
        SquareMat result(this->n);

        // Add corresponding elements of both matrices
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                result[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }

        return result;

    }


    // Matrix substraction
    SquareMat SquareMat::operator-(const SquareMat& other) const{

        // Ensure the matrices are of the same size
        if (this->n != other.n) {
            throw std::invalid_argument("Matrices must have the same size for substraction.");
        }
        SquareMat result(this->n);

        // Substract corresponding elements of both matrices
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                result[i][j] = this->matrix[i][j] - other.matrix[i][j];
            }
        }

        return result;

    }

    // Unary minus
    SquareMat SquareMat::operator-() const{
        // Create a new matrix to store the result
        SquareMat result(this->n);

        // Add minus for each number in the matrix
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                double val = this->matrix[i][j];
                result[i][j] = (val == 0.0) ? 0.0 : -val;
            }
        }

        return result;
    }

    // Matrix multiplication 
    SquareMat SquareMat::operator*(const SquareMat& other) const{
        if (this->n != other.n) {
            throw std::invalid_argument("Matrix sizes must match for multiplication.");
        }

        SquareMat result(this->n);
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                double sum = 0;
                for (int k = 0; k < this->n; ++k) {
                    sum += this->matrix[i][k] * other.matrix[k][j];
                }
                result[i][j] = sum;
            }
        }
        return result;
    }


    // Multiply by scalar from the right
    SquareMat SquareMat::operator*(int scalar) const {
        SquareMat result(this->n);
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                result[i][j] = this->matrix[i][j] * scalar;
            }
        }
        return result;
    }

    // Multiply by scalar from the left (non member friend function)
    SquareMat operator*(int scalar, const SquareMat& matrix) {
        return matrix * scalar;
    }


    // Multiply 2 matrices- each value in the matrix with the corresponding value in the other matrix
    SquareMat SquareMat::operator%(const SquareMat& other) const{
        // Ensure the matrices are of the same size
        if (this->n != other.n) {
            throw std::invalid_argument("Matrices must have the same size for Multiplication.");
        }
        SquareMat result(this->n);

        // Multiply corresponding elements of both matrices
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                result[i][j] = this->matrix[i][j] * other.matrix[i][j];
            }
        }

        return result;
    }


    // Modolu with scalar for each numer in the matrix
    SquareMat SquareMat::operator%(int scalar) const{
        if (scalar == 0) {
            throw std::domain_error("Modulo by zero scalar.");
        }

        SquareMat result(this->n);
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                result[i][j] = std::fmod(this->matrix[i][j], scalar); // For floating-point modulo
            }
        }
        return result;
    }


    // Divide each number in the matrix by a given scalar
    SquareMat SquareMat::operator/(int scalar) const{
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        
        SquareMat result(this->n);
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                result[i][j] = this->matrix[i][j] / scalar;
            }
        }
        return result;
    }

    // Multiply the matrix by itself 'power' times
    SquareMat SquareMat::operator^(int power) const{
        if (power < 0) {
            throw std::invalid_argument("Negative powers are not supported.");
        }

        SquareMat result(this->n);

        // Initialize result as identity matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = (i == j) ? 1 : 0;
            }
        }

        if (power == 0) {
            return result;
        }

        // Multiply result by the matrix 'power' times
        for (int i = 0; i < power; ++i) {
            result = result * (*this);
        }
      
        return result;
    }

    // ++mat
    // increments the matrix first, then returns a reference to the updated matrix.
    SquareMat& SquareMat::operator++(){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                ++matrix[i][j];
            }   
        }
            
        return *this;
    } 

    // mat++
    // copies the current matrix, then increments the original 
    // and returns the copy before increment
    SquareMat SquareMat::operator++(int){
        SquareMat temp = *this; 
        ++(*this);
        return temp;
    }  

    // --mat
    SquareMat& SquareMat::operator--(){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                --matrix[i][j];
            }   
        }
            
        return *this;

    } 

    // mat--
    SquareMat SquareMat::operator--(int){
        SquareMat temp = *this; 
        --(*this); 
        return temp;
    }


    // Matrix transpose 
    SquareMat SquareMat::operator~() const{
        SquareMat result(this->n);

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                result[i][j] = matrix[j][i];
            }   
        }
        return result;
    }


    // Gets the data with option to change it
    double* SquareMat::operator[](int row) {
        if (row < 0 || row >= n) {
            throw std::out_of_range("Index out of range.");
        }
        return matrix[row];
    }


    // Gets the data without changing it
    const double* SquareMat::operator[](int row) const{
        if (row < 0 || row >= n) {
            throw std::out_of_range("Index out of range.");
        }
        return matrix[row];
    }


    // Equality comparison by the sum of the matrix values
    bool SquareMat::operator==(const SquareMat& other) const {
        return this->matrixSum(*this) == matrixSum(other);
    }


    // Not equals, by sum of matrix values
    bool SquareMat::operator!=(const SquareMat& other) const{
        return !(*this == other);
    }


    // Smaller then, by sum of matrix values
    bool SquareMat::operator<(const SquareMat& other) const{
        return this->matrixSum(*this) < matrixSum(other);
    }


    // Bigger then, by sum of matrix values
    bool SquareMat::operator>(const SquareMat& other) const{
        return this->matrixSum(*this) > matrixSum(other);
    }


    // Smaller then or equals, by sum of matrix values
    bool SquareMat::operator<=(const SquareMat& other) const{
        double sum1 = matrixSum(*this);
        double sum2 = matrixSum(other);
        return sum1 <= sum2;    }


    // Bigger then or equals, by sum of matrix values
    bool SquareMat::operator>=(const SquareMat& other) const{
        double sum1 = matrixSum(*this);
        double sum2 = matrixSum(other);
        return sum1 >= sum2;    }


    // Helper function to calculate the sum of the matrix
    double SquareMat::matrixSum(const SquareMat& mat) const{
        double sumMat = 0;
        for (int i = 0; i < mat.n; ++i){
            for (int j = 0; j < mat.n; ++j){
                sumMat += mat[i][j];
            }
        }
        return sumMat;
    }


    // Determinant
    double SquareMat::operator!() const{
        // For matrix 1x1
        if (n == 1) {
            return matrix[0][0];
        }
        // For matrix 2x2
        if (n == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
        
        // For n > 2
        double det = 0;
        for (int col = 0; col < n; ++col) {
            // Create a minor matrix
            SquareMat minorMat(n - 1);
            for (int i = 1; i < n; ++i) {
                int minorCol = 0;
                for (int j = 0; j < n; ++j) {
                    if (j == col) continue;
                    minorMat[i - 1][minorCol] = matrix[i][j];
                    ++minorCol;
                }
            }

            // Recursive call
            double sign = (col % 2 == 0) ? 1 : -1;
            det += sign * matrix[0][col] * !minorMat;
        }

        return det;
    }


    // Compound operator for addition
    SquareMat& SquareMat::operator+=(const SquareMat& other){
        if (this->n != other.n) {
            throw std::invalid_argument("Matrix dimensions must match for addition.");
        }
    
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                this->matrix[i][j] += other[i][j];
            }
        }
    
        return *this;

    }


    // Compound operator for substraction
    SquareMat& SquareMat::operator-=(const SquareMat& other){
        if (this->n != other.n) {
            throw std::invalid_argument("Matrix dimensions must match for subtraction.");
        }
    
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                this->matrix[i][j] -= other[i][j];
            }
        }
    
        return *this;
    }

    // Compound operator for matrix multiplication
    SquareMat& SquareMat::operator*=(const SquareMat& other){
        if (this->n != other.n) {
            throw std::invalid_argument("Matrix dimensions must match for multiplication.");
        }
    
        SquareMat result = (*this) * other; // Use your existing operator*
        *this = result; // Use copy assignment instead of move
        return *this;

    }

    // Compound operator for matrix multiplication by scalar
    SquareMat& SquareMat::operator*=(int scalar){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                matrix[i][j] *= scalar;
            }
        }
        return *this;
    }


    // Compound operator for matrix division by scalar
    SquareMat& SquareMat::operator/=(int scalar){
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero.");
        }

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                matrix[i][j] /= scalar;
            }
        }

        return *this;
    }


    // Multiply number by the number in the corresponding place in thre second matrix
    SquareMat& SquareMat::operator%=(const SquareMat& other){

        if (this->n != other.n) {
            throw std::invalid_argument("Matrix dimensions must match for element-wise modulo.");
        }
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = this->matrix[i][j] * other.matrix[i][j];
            }
        }
        return *this;
    }


    // Modulo operation with scalar
    SquareMat& SquareMat::operator%=(int scalar){
        if (scalar == 0) {
            throw std::domain_error("Modulo by zero scalar.");
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = std::fmod(matrix[i][j], scalar);
            }
        }
        return *this;

    }


    // Compound operator for matrix printing
    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.n; ++i) {
            if (mat.matrix[i] == nullptr) {
                os << "[ uninitialized row ]" << std::endl;
                continue;
            }
            for (int j = 0; j < mat.n; ++j) {
                os << mat.matrix[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }


    // Assignment operator
    SquareMat& SquareMat::operator=(SquareMat&& other) noexcept {
        if (this != &other) {
            // Free current matrix
            for (int i = 0; i < n; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
    
            // Steal other's resources
            this->n = other.n;
            this->matrix = other.matrix;
    
            // Null out other's matrix so its destructor won't delete it
            other.matrix = nullptr;
            other.n = 0;
        }
        return *this;
    }


    // Assignment operator
    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this != &other) {
            // Free current matrix
            if (matrix != nullptr) {
                for (int i = 0; i < n; ++i) {
                    delete[] matrix[i];
                }
                delete[] matrix;
            }
            
            n = other.n;
    
            // Allocate new memory
            matrix = new double*[n];
            for (int i = 0; i < n; ++i) {
                matrix[i] = new double[n];
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        return *this;
    }
    


}