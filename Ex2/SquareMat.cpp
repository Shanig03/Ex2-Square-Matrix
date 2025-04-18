#include "SquareMat.hpp"

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
            throw std::invalid_argument("Matrices must have the same size for addition.");
        }
        // Create a new matrix to store the result
        SquareMat result(this->n);

        // Add corresponding elements of both matrices
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

        // Add corresponding elements of both matrices
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                double val = this->matrix[i][j];
                result[i][j] = (val == 0.0) ? 0.0 : -val;
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

}