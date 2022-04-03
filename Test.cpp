#include "doctest.h"
#include "Matrix.hpp"
#include <stdexcept>
#include <string>

using namespace zich;
using namespace std;


TEST_CASE("good input"){
    SUBCASE("+(2 matrices)"){
        std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
        zich::Matrix a{identity, 3, 3};
        zich::Matrix b{arr, 3, 3};
        zich::Matrix c = a+b;
        CHECK((a+b==c));
    }
    SUBCASE("+="){
        std::vector<double> identity = {3, 0, 0, 0, 3, 0, 0, 0, 3};
        std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
        zich::Matrix a{identity, 3, 3};
        zich::Matrix b{arr, 3, 3};
        CHECK_EQ((a == b), true);
        a = a+=b;
        CHECK_EQ((a == b), false);
    }
    SUBCASE("+(unary"){

    }
    SUBCASE("++"){

    }
    SUBCASE("-="){

    }
    SUBCASE("-(2 matrices)"){

    }
    SUBCASE("-(unary)"){

    }
    SUBCASE("--"){

    }
    SUBCASE("compare operators"){

    }
    SUBCASE("*=(scalar)"){

    }
    SUBCASE("*(scalar)"){

    }
    SUBCASE("*=(matrix)"){

    }
    SUBCASE("*(matrix)"){

    }

}

TEST_CASE("bad matrix building"){
    vector<double>v1;
    for (double i = 0; i < 12; i++){
        v1.push_back(i);
    }
    CHECK_THROWS(Matrix(v1,3,5));

    vector<double>v2;
    for (double i = 0; i < 9; i++){
        v2.push_back(i);
    }
    CHECK_THROWS(Matrix(v1,3,2));

    CHECK_THROWS(Matrix(v1,3,-3));
    CHECK_THROWS(Matrix(v1,-3,-3));
    CHECK_THROWS(Matrix(v1,-3,3));
    CHECK_THROWS(Matrix(v1,0,3));
    CHECK_THROWS(Matrix(v1,3,0));
}

TEST_CASE("bad input"){
    vector<double>v1;
    for (double i = 0; i < 12; i++){
        v1.push_back(i);
    }
    vector<double>v2;
    for (double i = 0; i < 9; i++){
        v2.push_back(i);
    }
    vector<double>v3;
    for (double i = 0; i < 8; i++){
        v3.push_back(i);
    }
    Matrix m1{v1,3,4};
    Matrix m2{v2,3,3};
    Matrix m3{v3,4,2};
    CHECK_THROWS(m1 + m2);
    CHECK_THROWS(m1 += m3);
    CHECK_THROWS(m2 - m3);
    CHECK_THROWS(m1 -= m2);
    CHECK_THROWS(m1 - m2);
    CHECK_THROWS(m3 + m2);
    CHECK_THROWS(m2 -= m1);
    CHECK_THROWS(m2 += m3);
}