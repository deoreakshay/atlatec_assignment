//
// Created by akshay on 06.02.20.
//

#include "matrix.h"

Matrix Matrix::operator+(const Vector &vector)
{
    if(number_of_rows_ != vector.GetNumberofRows() || number_of_column_ != 1)
    {
        std::cout << "Rows and Columns of Matrix and Vector must be Equal(defined) for Matrix addition." << std::endl;
        return Matrix();
    }
    Matrix result_matrix(number_of_rows_,number_of_column_,0);
    Matrix vector_to_matrix = ConvertVectorToMatrix(vector);
    for(int row{0}; row < number_of_rows_; ++row)
    {
        for(int column{0}; column < number_of_column_; ++column)
        {
            result_matrix(row, column) = this->matrix_[row][column] + vector_to_matrix(row, column);
        }
    }
    return result_matrix;
}

Matrix Matrix::operator*(const Vector &vector)
{
    if(number_of_column_ != vector.GetNumberofRows())
    {
        std::cout << " Matrix column and Vector rows(dimensions) must be equal for Multiplication." << std::endl;
        return Matrix();
    }

    Matrix vector_to_matrix = ConvertVectorToMatrix(vector);
    Matrix result_matrix(number_of_rows_,vector_to_matrix.number_of_column_,0);
    for(int row{0}; row < number_of_rows_; ++row)
    {
        for(int column{0}; column < vector_to_matrix.number_of_column_; ++column)
        {
            for (int temp{0}; temp < number_of_column_ ; ++temp)
            {
                result_matrix(row, column) += this->matrix_[row][temp] * vector_to_matrix(temp, column);
            }
        }
    }
    return result_matrix;
}

Matrix Matrix::operator*(const int scalar)
{
    Matrix result_matrix(number_of_rows_, number_of_column_, 0);
    for(int row{0}; row < number_of_rows_; ++row)
    {
        for(int column{0}; column < number_of_column_; ++column)
        {
            result_matrix(row, column) = this->matrix_[row][column] * scalar;
        }
    }
    return result_matrix;
}

int& Matrix::operator()(const int &row, const int &column)
{
    return this->matrix_[row][column];
}

void Matrix::DisplayMatrixData()
{
    if(matrix_.empty())
    {
        std::cout << " Matrix is not created!!!" << std::endl;
    }
    else
    {
        for(int row{0}; row < number_of_rows_; ++row)
        {
            for(int column{0}; column < number_of_column_; ++column)
            {
                std::cout << "\t\t" << matrix_[row][column] << "\t";
            }
            std::cout << std::endl;
        }
    }
}

Matrix Matrix::ConvertVectorToMatrix(const Vector &vector)
{
    Matrix vector_to_matrix(vector.GetNumberofRows(), 1, vector.GetDefaultValue());
    return vector_to_matrix;
}