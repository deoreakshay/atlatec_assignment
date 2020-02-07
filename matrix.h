//
// Created by akshay on 06.02.20.
//

#ifndef ATLATEC_ASSIGNMENT_MATRIX_H
#define ATLATEC_ASSIGNMENT_MATRIX_H

#include "vector.h"

class Matrix
{
public:
    Matrix(): matrix_()
    {
    }
    Matrix(int rows, int columns, int default_value)
        : number_of_rows_(rows), number_of_column_(columns)
    {
        matrix_.resize(number_of_rows_, std::vector<int>(number_of_column_,default_value));
    }
    Matrix(int rows, int columns)
            : number_of_rows_(rows), number_of_column_(columns)
    {
        matrix_.resize(number_of_rows_, std::vector<int>(number_of_column_));
    }
    ~Matrix()
    {
        for(auto element : matrix_)
        {
            element.clear();
        }
        matrix_.clear();
    }

    Matrix operator+(const Vector& vector);
    Matrix operator*(const Vector& vector);
    Matrix operator*(const int& scalar);
    int& operator()(const int& row, const int& column);
    void DisplayMatrixElements();
    Matrix ConvertVectorToMatrix(const Vector& vector);

private:
    int number_of_rows_{};
    int number_of_column_{};
    std::vector<std::vector<int>> matrix_;
};
#endif //ATLATEC_ASSIGNMENT_MATRIX_H
