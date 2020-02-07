//
// Created by akshay on 06.02.20.
//

#ifndef ATLATEC_ASSIGNMENT_VECTOR_H
#define ATLATEC_ASSIGNMENT_VECTOR_H

#include <iostream>
#include <vector>

class Vector
{
public:
    Vector()
        : multidimensional_vector_()
    {
    }
    Vector(int size)
        : number_of_dimensions_(size),multidimensional_vector_(number_of_dimensions_)
    {
    }
    Vector(int size, int default_value)
        : number_of_dimensions_(size),multidimensional_vector_(number_of_dimensions_,default_value)
    {
    }
    ~Vector()
    {
        multidimensional_vector_.clear();
    }
    Vector operator*(const int& scalar);
    int GetNumberofRows() const ;
    int GetDefaultValue() const;
    void DisplayVectorElements();

private:
    int number_of_dimensions_{};
    std::vector<int> multidimensional_vector_{};
};
#endif //ATLATEC_ASSIGNMENT_VECTOR_H
