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


    //std::cout << matrix - mat << std::endl;
    //std::cout << -mat << std::endl;

    //std::cout << matrix + mat << std::endl;

    /*
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
    */

    std::cout << "matrix ^2:\n" << (matrix^3) << std::endl;






    return 0;
}