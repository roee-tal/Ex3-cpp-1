#include "Matrix.hpp"
namespace zich{

Matrix::Matrix(std::vector<double> data, const int row, const int col):row(row),col(col)
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
}

void Matrix:: is_legal(Matrix const &mat)const{
    if(this->row != mat.row || this->col != mat.col){
        throw std::invalid_argument("row and col must be equal");
    }
}

Matrix Matrix::operator+(Matrix const &mat){
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

 Matrix operator+(Matrix& mat){
     Matrix unary_mat{mat.data,mat.row,mat.col};
     return unary_mat;
 }

Matrix& Matrix::operator++(){
     for(int i = 0; i < this->data.size(); i++)
     {
         this->data[size_t(i)] += 1;
     }
     return *this;
 }

Matrix Matrix::operator++(const int num){
    Matrix copy = *this;
    for(int i = 0; i < this->data.size(); i++)
     {
         this->data[size_t(i)] += 1;
     }
     return copy;

}

Matrix Matrix::operator--(const int num){
    Matrix copy = *this;
    for(int i = 0; i < this->data.size(); i++)
    {
         this->data[size_t(i)] -= 1;
    }
    return copy;
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

Matrix operator-(Matrix& mat){
    Matrix unary_neg{mat.data,mat.row,mat.col};
    for (int i = 0; i < mat.data.size(); i++)
    {   
        if(mat.data[size_t(i)] == 0){
            continue;
        }
        unary_neg.data[size_t(i)] = (-1)*(mat.data[size_t(i)]);
        
    }
    return unary_neg;
}

double Matrix::sum_mat()const{
    double sum = 0;
    for (int i = 0; i < this->data.size(); i++)
    {
        sum += this->data[size_t(i)];
    }
    return sum;
}

bool Matrix::operator>(Matrix& mat){
    is_legal(mat);
    return this->sum_mat() > mat.sum_mat();
}

bool Matrix::operator>=(Matrix& mat){
    is_legal(mat);
    return this->sum_mat() >= mat.sum_mat();
}

bool Matrix::operator<(Matrix& mat){\
    is_legal(mat);
    return this->sum_mat() < mat.sum_mat();
}

bool Matrix::operator<=(const Matrix& mat)const{
    is_legal(mat);
    return this->sum_mat() <= mat.sum_mat();
}

bool Matrix::operator!=(Matrix& mat){
    is_legal(mat);
    return this->sum_mat() != mat.sum_mat();
}

bool Matrix:: operator==(Matrix& mat){
    is_legal(mat);
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < this->data.size(); i++){
        if(this->data[size_t(i)] != mat.data[size_t(i)])
        {
            return false;
        }
    }
    return true;
}

Matrix Matrix::operator*(const double scalar){
    Matrix mat_res{this->data,this->row,this->col};
    for (int i = 0; i < mat_res.data.size(); i++)
    {
        mat_res.data[size_t(i)] = this->data[size_t(i)] * scalar;
    }
    return mat_res;
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

Matrix Matrix::operator*(const Matrix &mat){
    if(this->col != mat.row){
        throw std::runtime_error("left matrix's col has to be same to right matrix row");
    }
    std::vector<double> vector1;
    vector1.resize((unsigned int)(this->row * mat.col));
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            for (int k = 0; k < this->col; k++)
            {
                vector1[size_t(mat.col*i+j)] += this->data[size_t(this->col*i+k)]*mat.data[size_t(mat.col*k+j)];
            }
        }
    }
    Matrix mat3(vector1, this->row, mat.col);
    return mat3;
}

Matrix& Matrix::operator*=(const Matrix &mat){
    if(this->col != mat.row){
        throw std::runtime_error("left matrix's col has to be same to right matrix row");
    }
    std::vector<double> mat3_data;
    mat3_data.resize((unsigned int)(this->row * mat.col));
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            for (int k = 0; k < this->col; k++)
            {
                mat3_data[size_t(mat.col*i+j)] += this->data[size_t(this->col*i+k)]*mat.data[size_t(mat.col*k+j)];
            }
        }
    }
    this->data = mat3_data;
    this->col = mat.col;
    return *this;
}

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