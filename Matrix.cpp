#include "Matrix.hpp"
namespace zich{

Matrix::Matrix(std::vector<double> data, const int row, const int col)
{
    if (row <= 0 || col <= 0)
    {
        throw std::runtime_error("row or col can't be negative");
    }
    if(row * col != data.size())
    {
         throw std::runtime_error("row*col should be same to the matrix size");
    }
    this->data = std::move(data);
    this->row = row;
    this->col = col;
}

void Matrix:: is_legal(Matrix const &mat)const{
    if(this->row != mat.row || this->col != mat.col){
        throw std::invalid_argument("row and col must be equal");
    }
}

Matrix Matrix::operator+(Matrix const &mat){
    // if(this->row != mat.row || this->col != mat.row){
    //     throw std::invalid_argument("row and col must be equal");
    // }
    is_legal(mat);
    Matrix mat_res{this->data,row,col};
    for (int i = 0; i < mat_res.data.size(); i++)
    {
        mat_res.data[size_t(i)] = this->data[size_t(i)] + mat.data[size_t(i)];
    }
    return mat_res;
}

Matrix& Matrix::operator+=(Matrix const &mat){
    is_legal(mat);
    for (int i = 0; i < this->data.size(); i++)
    {
        this->data[size_t(i)] += mat.data[size_t(i)];
    }
    return *this;
 }

 Matrix Matrix::operator+(){
     Matrix unary_mat{this->data,this->row,this->col};
     return unary_mat;
 }

 Matrix& Matrix::operator++(){
     for(int i = 0; i < this->data.size(); i++)
     {
         this->data[size_t(i)] += 1;
     }
     return *this;
 }

Matrix Matrix::operator-(Matrix const &mat){
    is_legal(mat);
    Matrix mat_res{this->data,row,col};
    for (int i = 0; i < mat_res.data.size(); i++)
    {
        mat_res.data[size_t(i)] = this->data[size_t(i)] - mat.data[size_t(i)];
    }
    return mat_res;
 }

Matrix& Matrix::operator-=(const Matrix& mat){
    is_legal(mat);
    for (int i = 0; i < this->data.size(); i++)
    {
        this->data[size_t(i)] -= mat.data[size_t(i)];
    }
    return *this;
 }

Matrix& Matrix::operator--(){
    for(int i = 0; i < this->data.size(); i++)
    {
         this->data[size_t(i)] -= 1;
    }
    return *this;
}

Matrix Matrix::operator-(){
    Matrix unary_neg{this->data,row,col};
    for (int i = 0; i < this->data.size(); i++)
    {   
        if(this->data[size_t(i)] == 0){
            continue;
        }
        unary_neg.data[size_t(i)] = (-1)*(this->data[size_t(i)]);
        
    }
    return unary_neg;
}

double Matrix::sum_mat(){
    double sum = 0;
    for (int i = 0; i < this->data.size(); i++)
    {
        sum += this->data[size_t(i)];
    }
    return sum;
}

bool Matrix::operator>(Matrix& mat){
    return this->sum_mat() > mat.sum_mat();
}

bool Matrix::operator>=(Matrix& mat){
    return this->sum_mat() >= mat.sum_mat();
}

bool Matrix::operator<(Matrix& mat){
    return this->sum_mat() < mat.sum_mat();
}

bool Matrix::operator<=(Matrix& mat){
    return this->sum_mat() <= mat.sum_mat();
}

bool Matrix::operator!=(Matrix& mat){
    return this->sum_mat() != mat.sum_mat();
}

bool Matrix:: operator==(Matrix& mat){
    is_legal(mat);
    double sum1 = this->sum_mat();
    double sum2 = mat.sum_mat();
    return (sum1 == sum2);
}

Matrix& Matrix::operator*=(const double scalar){
    for (int i = 0; i < this->data.size(); i++){
        this->data[size_t(i)] = this->data[size_t(i)]*scalar; 
    }
    return *this;

}

Matrix operator*(const double scalar, Matrix &mat){
    Matrix mat_res{mat.data,mat.row,mat.col};
    for (int i = 0; i < mat_res.data.size(); i++)
    {
        mat_res.data[size_t(i)] = mat.data[size_t(i)] * scalar;
    }
    return mat_res;
}

// Matrix& Matrix::operator*=(const Matrix &mat){
//     is_legal(mat);
// }

std::ostream& operator << (std::ostream &out, const Matrix &mat){
    for (int i = 0; i < mat.row; i++){
        out << '[';
        for (int j = 0; j < mat.col; j++)
        {
            if (j != mat.col -1 )
            {
                out << mat.data[(unsigned int)(i * mat.col + j)] << ' ';
            }
            else{
                out <<mat.data[(unsigned int)(i * mat.col + j)];
            }
        }
        out << ']' << '\n';
    }
    return out;
}


}