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

    mat *= matrix;
    std::cout << "multiply mat by matrix: \n" << mat << std::endl;

    matrix /= 2;
    std::cout << "divide matrix by 2: \n" << matrix << std::endl;

    //std::cout << matrix - mat << std::endl;
    //std::cout << -mat << std::endl;

    //std::cout << matrix + mat << std::endl;

    /*

    mat += matrix;
    std::cout << "added matrix to mat: \n" << mat << std::endl;
    matrix -= mat;
    std::cout << "substract matrix from mat: \n" << matrix << std::endl;


    std::cout << 2 * mat << std::endl;
    std::cout << matrix * 3 << std::endl;

    std::cout << matrix % mat << std::endl;

    std::cout << matrix % 2 << std::endl;

    std::cout << matrix / 2 << std::endl;
    std::cout << "matrix++ :\n" << matrix++ << std::endl;
    std::cout << "++mat :\n" << ++mat << std::endl;
    std::cout << "matrix :\n" << matrix << std::endl;

    std::cout << "matrix-- :\n" <<  matrix-- << std::endl;
    std::cout << "--mat :\n" << --mat << std::endl;
    std::cout << "matrix :\n" <<matrix << std::endl;
    std::cout << "matrix multiply mat:\n" << matrix*mat << std::endl;
    std::cout << "matrix ^2:\n" << (matrix^3) << std::endl;

    std::cout << "matrix equals?:\n" << (mat2 == matrix2) << std::endl;

    std::cout << "matrix not equals?:\n" << (mat2 != matrix2) << std::endl;

    std::cout << ">?:\n" << (mat2 > matrix2) << std::endl;

    std::cout << "<:\n" << (mat2 < matrix2) << std::endl;

    std::cout << ">=?:\n" << (mat2 >= matrix2) << std::endl;

    std::cout << "<=:\n" << (mat2 <= matrix2) << std::endl;
    */

    
    //std::cout << "matrix equals?:\n" << (mat == matrix) << std::endl;

    squareMatrix::SquareMat mat2(3);

    mat2[0][0] = -2;
    mat2[0][1] = 2;
    mat2[0][2] = -3;
    mat2[1][0] = -1;
    mat2[1][1] = 1;
    mat2[1][2] = 3;
    mat2[2][0] = 2;
    mat2[2][1] = 0;
    mat2[2][2] = -1;

    
    //std::cout << "matrix determinant:\n" << (!mat2) << std::endl;


    return 0;
}