#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <sstream>
#include <stdexcept>


using namespace squareMatrix;

TEST_CASE("Constructor and Destructor") {
    SquareMat mat(2);
    CHECK(mat[0][0] == 0.0);
    CHECK(mat[1][1] == 0.0);
}

TEST_CASE("Copy constructor and assignment") {
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    SquareMat mat2 = mat1;
    CHECK(mat2[0][0] == 1);
    CHECK(mat2[1][1] == 4);

    SquareMat mat3(2);
    mat3 = mat1;
    CHECK(mat3[0][1] == 2);
}

TEST_CASE("Addition and Subtraction") {
    SquareMat a(2), b(2);
    a[0][0] = 1; 
    a[1][1] = 2;

    b[0][0] = 3; 
    b[1][1] = 4;
    
    SquareMat c = a + b;
    CHECK(c[0][0] == 4);
    CHECK(c[1][1] == 6);
    
    SquareMat d = b - a;
    CHECK(d[0][0] == 2);
    CHECK(d[1][1] == 2);
}

TEST_CASE("Unary minus") {
    SquareMat a(2);
    a[0][0] = 1; 
    a[1][1] = -2;
    
    SquareMat b = -a;
    CHECK(b[0][0] == -1);
    CHECK(b[1][1] == 2);
}

TEST_CASE("Matrix multiplication") {
    SquareMat a(2), b(2);
    a[0][0] = 1; 
    a[0][1] = 2;
    a[1][0] = 3; 
    a[1][1] = 4;

    b = a;
    
    SquareMat c = a * b;
    CHECK(c[0][0] == 7);
    CHECK(c[0][1] == 10);
    CHECK(c[1][0] == 15);
    CHECK(c[1][1] == 22);
}

TEST_CASE("Scalar multiplication and division") {
    SquareMat a(2);
    a[0][0] = 2; 
    a[1][1] = 4;
    
    SquareMat b = a * 2;
    SquareMat c = 2 * a;
    SquareMat d = a / 2;
    
    CHECK(b[0][0] == 4);
    CHECK(c[1][1] == 8);
    CHECK(d[1][1] == 2);
}

TEST_CASE("Matrix multiplication number by the corresponding number") {
    SquareMat a(2);
    a[0][0] = 5; 
    a[1][1] = 8;

    SquareMat b(2);
    b[0][0] = 3; 
    b[1][1] = 5;

    SquareMat c = a % b;

    CHECK(c[0][0] == 15);
    CHECK(c[1][1] == 40);
    CHECK(c[0][1] == 0);
    CHECK(c[1][0] == 0);

}

TEST_CASE("Scalar modulu") {
    SquareMat a(2);
    a[0][0] = 5; 
    a[1][1] = 8;

    SquareMat b(2);
    b[0][0] = 3; 
    b[1][1] = 5;
    
    SquareMat c = a % 3;
    
    CHECK(c[0][0] == 2);
    CHECK(c[1][1] == 2);
    CHECK(c[0][1] == 0);
    CHECK(c[1][0] == 0);

}

TEST_CASE("Power of matrix") {
    SquareMat a(2);
    a[0][0] = 1; 
    a[0][1] = 1;
    a[1][0] = 1; 
    a[1][1] = 0;
    
    SquareMat b = a ^ 2;
    CHECK(b[0][0] == 2);
    CHECK(b[0][1] == 1);
    CHECK(b[1][0] == 1);
    CHECK(b[1][1] == 1);
}

TEST_CASE("Transpose") {
    SquareMat a(2);
    a[0][1] = 5;
    a[1][0] = 7;
    
    SquareMat b = ~a;
    CHECK(b[0][1] == 7);
    CHECK(b[1][0] == 5);
}

TEST_CASE("Increment and Decrement") {
    SquareMat a(2);
    a[0][0] = 1;
    
    SquareMat b = ++a;
    CHECK(b[0][0] == 2);
    
    SquareMat c = a++;
    CHECK(c[0][0] == 2);
    CHECK(a[0][0] == 3);
    
    SquareMat d = --a;
    CHECK(d[0][0] == 2);
    
    SquareMat e = a--;
    CHECK(e[0][0] == 2);
    CHECK(a[0][0] == 1);
}

TEST_CASE("Comparison Operators") {
    SquareMat a(2), b(2);
    a[0][0] = 1; 
    a[1][1] = 1;

    b[0][0] = 2; 
    b[1][1] = 2;

    CHECK(a != b);
    CHECK(a < b);
    CHECK(b > a);
    CHECK(a <= b);
    CHECK(b >= a);
    CHECK_FALSE(a == b);
}

TEST_CASE("Determinant (! operator)") {
    SquareMat a(2);
    a[0][0] = 1; 
    a[0][1] = 2;
    a[1][0] = 3; 
    a[1][1] = 4;
    
    double det = !a;
    CHECK(det == doctest::Approx(-2.0));//??
}

TEST_CASE("Compound assignment operators") {
    SUBCASE("Addition and substraction"){
        SquareMat a(2), b(2);
        a[0][0] = 1; 

        b[0][0] = 2;
        
        a += b;
        CHECK(a[0][0] == 3);

        a -= b;
        CHECK(a[0][0] == 1);
    }
    
    SUBCASE("Multiply by matrix and scalar"){

        SquareMat c(2), d(2);
        c[0][0] = 1; 
        
        d[0][0] = 2;

        c *= d;
        CHECK(c[0][0] == 2);

        c *= 2;
        CHECK(c[0][0] == 4);
    }

    SUBCASE("Division by scalar"){

        SquareMat c(2);
        c[0][0] = 1; 
        
        c /= 2;
        CHECK(c[0][0] == 0.5);
    }

    
    SUBCASE("Multiplication and modulo"){

        SquareMat c(2) , d(2);
        c[0][0] = 1; 
        d[0][0] = 2;
        
        c %= d;
        CHECK(c[0][0] == 2);

        c %= 2;
        CHECK(c[0][0] == 0);
    }
    
}

TEST_CASE("Test Exceptions"){
    // Test case for constructor exception
    SUBCASE("SquareMat Constructor Exception") {
        CHECK_THROWS_AS(SquareMat(-1), std::invalid_argument); // Negative size
    }

    // Test case for addition operator exception
    SUBCASE("SquareMat Addition Operator Exception") {
        SquareMat mat1(3);
        SquareMat mat2(2);
        CHECK_THROWS_AS(mat1 + mat2, std::invalid_argument);  // Matrices with different sizes
    }

    // Test case for subtraction operator exception
    SUBCASE("SquareMat Subtraction Operator Exception") {
        SquareMat mat1(3);
        SquareMat mat2(2);
        CHECK_THROWS_AS(mat1 - mat2, std::invalid_argument);  // Matrices with different sizes
    }

    // Test case for multiplication operator exception
    SUBCASE("SquareMat Multiplication Operator Exception") {
        SquareMat mat1(3); 
        SquareMat mat2(2); 
        CHECK_THROWS_AS(mat1 * mat2, std::invalid_argument);  // Matrices with different sizes
    }

    // Test case for modulo operator exception with scalar 0
    SUBCASE("SquareMat Modulo Operator Exception (Scalar)") {
        SquareMat mat(3);
        CHECK_THROWS_AS(mat % 0, std::domain_error);  // Modulo by zero
    }

    // Test case for division operator exception with scalar 0
    SUBCASE("SquareMat Division Operator Exception (Scalar)") {
        SquareMat mat(3); 
        CHECK_THROWS_AS(mat / 0, std::invalid_argument);  // Division by zero
    }

    // Test case for negative power exception
    SUBCASE("SquareMat Power Operator Exception") {
        SquareMat mat(3);  
        CHECK_THROWS_AS(mat ^ -1, std::invalid_argument);  // Negative power
    }

    // Test case for out-of-bounds index exception
    SUBCASE("SquareMat Index Operator Exception") {
        SquareMat mat(3); 
        CHECK_THROWS_AS(mat[3], std::out_of_range);  // Index out of bounds (row 3 in a 3x3 matrix)
        CHECK_THROWS_AS(mat[-1], std::out_of_range);  // Negative index
    }

    // Test case for matrix addition with mismatched dimensions for compound assignment
    SUBCASE("SquareMat Compound Addition Operator Exception") {
        SquareMat mat1(3); 
        SquareMat mat2(2); 
        CHECK_THROWS_AS(mat1 += mat2, std::invalid_argument);  // Matrices with different sizes
    }

    // Test case for matrix subtraction with mismatched dimensions for compound assignment
    SUBCASE("SquareMat Compound Subtraction Operator Exception") {
        SquareMat mat1(3);  
        SquareMat mat2(2); 
        CHECK_THROWS_AS(mat1 -= mat2, std::invalid_argument);  // Matrices with different sizes
    }

    // Test case for matrix multiplication with mismatched dimensions for compound assignment
    SUBCASE("SquareMat Compound Multiplication Operator Exception") {
        SquareMat mat1(3); 
        SquareMat mat2(2); 
        CHECK_THROWS_AS(mat1 *= mat2, std::invalid_argument);  // Matrices with different sizes
    }

    // Test case for matrix division by zero for compound assignment
    SUBCASE("SquareMat Compound Division Operator Exception") {
        SquareMat mat(3); 
        CHECK_THROWS_AS(mat /= 0, std::invalid_argument);  // Division by zero
    }

    // Test case for matrix modulo by zero for compound assignment
    SUBCASE("SquareMat Compound Modulo Operator Exception") {
        SquareMat mat(3);  
        CHECK_THROWS_AS(mat %= 0, std::domain_error);  // Modulo by zero
    }
}
