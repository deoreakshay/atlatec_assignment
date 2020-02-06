#include <iostream>
#include "matrix.h"
#include "vector.h"

int main()
{
    int scalar{0};
    int number_of_rows{};
    int number_of_columns{};
    int vector_dimensions{};

    std::cout << "####################################" << std::endl;
    std::cout << "Welcome to Atlatec Coding Assignment" << std::endl;
    std::cout << "####################################" << std::endl;

    std::cout << "Please Enter Matrix details: " << std::endl;
    std::cout << "Number of Rows: ";
    std::cin >> number_of_rows;
    if(number_of_rows <= 0)
    {
        std::cout << "Please enter positive number: " << std::endl;
        std::cout << "Number of Rows: ";
        std::cin >> number_of_rows;
    }
    std::cout << "Number of Columns: ";
    std::cin >> number_of_columns;
    if(number_of_columns <= 0)
    {
        std::cout << "Please enter positive number: " << std::endl;
        std::cout << "Number of Columns: ";
        std::cin >> number_of_columns;
    }

    Matrix matrix(number_of_rows, number_of_columns, 5);

    std::cout << "Please Enter dimensions of Vector: ";
    std::cin >> vector_dimensions;
    if(vector_dimensions <= 0)
        std::cout << "Please enter positive number: " << std::endl;
    Vector vector(vector_dimensions, 4);

    std::cout << "Please Enter scalar value for scalar multiplication: ";
    std::cin >> scalar;

    std::cout << "####################################" << std::endl;
    std::cout << "      Results of Assignment       " << std::endl;
    std::cout << "####################################" << std::endl;

    std::cout << " Vector created with default value:" << std::endl;
    vector.DisplayVectorData();
    std::cout << " Matrix created with default value:" << std::endl;
    matrix.DisplayMatrixData();

    std::cout << "1) MATRIX and VECTOR Multiplication:" << std::endl;
    Matrix result_matrix = matrix * vector;
    result_matrix.DisplayMatrixData();

    std::cout << "2) MATRIX Scalar Multiplication:" << std::endl;
    Matrix scalar_matrix = matrix * scalar;
    scalar_matrix.DisplayMatrixData();

    std::cout << "3) VECTOR Scalar Multiplication:" << std::endl;
    Vector scalar_vector = vector * scalar;
    scalar_vector.DisplayVectorData();

    std::cout << "4) MATRIX and VECTOR Addition:" << std::endl;
    Matrix matrix_addition = matrix + vector;
    matrix_addition.DisplayMatrixData();

    return 0;

}
