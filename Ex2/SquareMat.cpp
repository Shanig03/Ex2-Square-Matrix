#include "SquareMat.hpp"
#include <cmath>

namespace squareMatrix {

    // Constractor
    SquareMat::SquareMat(int matrixSize){
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


    // Destractor
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


    SquareMat SquareMat::operator-(const SquareMat& other) const{

        // Ensure the matrices are of the same size
        if (this->n != other.n) {
            throw std::invalid_argument("Matrices must have the same size for substraction.");
        }
        // Create a new matrix to store the result
        SquareMat result(this->n);

        // Substract corresponding elements of both matrices
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                result[i][j] = this->matrix[i][j] - other.matrix[i][j];
            }
        }

        return result;

    }

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


    // Multiply from the right
    SquareMat SquareMat::operator*(int scalar) const {
        SquareMat result(this->n);
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                result[i][j] = this->matrix[i][j] * scalar;
            }
        }
        return result;
    }

    // Multiply from the left, non member friend function  
    SquareMat operator*(int scalar, const SquareMat& matrix) {
        // Just reuse the member operator
        return matrix * scalar;
    }

    SquareMat SquareMat::operator%(const SquareMat& other) const{
        // Ensure the matrices are of the same size
        if (this->n != other.n) {
            throw std::invalid_argument("Matrices must have the same size for Multiplication.");
        }
        // Create a new matrix to store the result
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

        // need to check if the scalar is an integer?

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
        SquareMat temp = *this; // Copy
        ++(*this); // Increment
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
        SquareMat temp = *this; // Copy
        --(*this); 
        return temp;
    }


    SquareMat SquareMat::operator~() const{
        SquareMat result(this->n);

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                result[i][j] = matrix[j][i];
                result[j][i] = matrix[i][j];
            }   
        }
        return result;
    }


    // Gets the data with option to change it
    double* SquareMat::operator[](int row) {
        if (row < 0 || row >= n) {
            throw std::out_of_range("Row index out of range.");
        }
        return matrix[row];
    }


    // Gets the data without changing it
    const double* SquareMat::operator[](int row) const{
        if (row < 0 || row >= n) {
            throw std::out_of_range("Row index out of range.");
        }
        return matrix[row];
    }


    //need to add SquareMat:: ??
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

}