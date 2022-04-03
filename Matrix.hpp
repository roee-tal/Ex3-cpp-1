#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

namespace zich{

    class Matrix{
      
        
            std::vector<double>data;
            int row;
            int col;
        public:
            Matrix(const int row,const int col);
            Matrix(const std::vector<double> data, const int row, const int col);
            void is_legal(const Matrix &mat) const;
            Matrix operator+(Matrix const &mat);
            Matrix& operator+=(const Matrix& mat);
            Matrix operator+();
            Matrix& operator++();
            Matrix operator-(Matrix const &mat);
            Matrix& operator-=(const Matrix& mat);
            Matrix& operator--();
            Matrix operator-();
            double sum_mat();
            bool operator>(Matrix& mat);
            bool operator>=(Matrix& mat);
            bool operator<(Matrix& mat);
            bool operator<=(Matrix& mat);
            bool operator==(Matrix& mat);
            bool operator!=(Matrix& mat);
            Matrix& operator*=(const double scalar);
            Matrix& operator*=(const Matrix &mat);
            friend Matrix operator*(const double scalar, Matrix &mat);
            friend std::ostream & operator << (std::ostream &out, const Matrix &mat);
            friend std::istream& operator>> (std::istream &os , Matrix& mat);

            
    };
}