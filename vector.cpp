//
// Created by akshay on 06.02.20.
//

#include "vector.h"

Vector Vector::operator*(const int& scalar_value)
{
    Vector scalar_vector(number_of_dimensions_);
    for(int item{0}; item < scalar_vector.multidimensional_vector_.size(); ++item)
    {
        scalar_vector.multidimensional_vector_[item] = this->multidimensional_vector_[item] * scalar_value;
    }
    return scalar_vector;
}

int Vector::GetNumberofRows() const
{
    return number_of_dimensions_;
}

int Vector::GetDefaultValue() const
{
    return multidimensional_vector_.at(0);
}

void Vector::DisplayVectorElements()
{
    for(int item{0}; item < multidimensional_vector_.size(); ++item)
    {
        std::cout << "\t\t" << multidimensional_vector_[item] << std::endl;
    }
}
