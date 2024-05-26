#include "vector.h"
#include <stdexcept>

Vector::Vector(size_t size)
{
    // init a vector of size `size` with zeros
    data_ = std::vector<double>(size, 0.0);
}

Vector::Vector(const std::vector<double> &data)
{
    data_ = data;
}

double &Vector::operator[](size_t index)
{
    return data_[index];
}

const double &Vector::operator[](size_t index) const
{
    return data_[index];
}

size_t Vector::size() const
{
    return size_t();
}

Vector Vector::operator+(const Vector &other) const
{
    // check if the two vectors have the same size
    if (data_.size() != other.data_.size())
    {
        throw std::invalid_argument("Vectors must have the same size");
    }

    // create a new vector to store the result
    Vector result(data_.size());

    // add the two vectors element-wise
    for (size_t i = 0; i < data_.size(); ++i)
    {
        result[i] = data_[i] + other[i];
    }

    return result;
}

Vector Vector::operator-(const Vector &other) const
{
    // check if the two vectors have the same size
    if (data_.size() != other.data_.size())
    {
        throw std::invalid_argument("Vectors must have the same size");
    }

    // create a new vector to store the result
    Vector result(data_.size());

    // subtract the two vectors element-wise
    for (size_t i = 0; i < data_.size(); ++i)
    {
        result[i] = data_[i] - other[i];
    }

    return result;
}

double Vector::dot(const Vector &other) const
{
    // check if the two vectors have the same size
    if (data_.size() != other.data_.size())
    {
        throw std::invalid_argument("Vectors must have the same size");
    }

    double result = 0.0;

    // compute the dot product of the two vectors
    for (size_t i = 0; i < data_.size(); ++i)
    {
        result += data_[i] * other[i];
    }

    return result;
}
