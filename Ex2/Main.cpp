#include "SquareMat.hpp"

int main(){
    squareMatrix::SquareMat matrix(2);

    matrix[0][0] = 1;
    matrix[0][1] = 3;
    matrix[1][0] = 2;
    matrix[1][1] = 4;

    squareMatrix::SquareMat mat(2);

    mat[0][0] = 0;
    mat[0][1] = 3;
    mat[1][0] = 2;
    mat[1][1] = 4;

    std::cout << matrix << std::endl;
    std::cout << mat << std::endl;


    std::cout << matrix - mat << std::endl;
    std::cout << -mat << std::endl;

    std::cout << matrix + mat << std::endl;

    return 0;
}