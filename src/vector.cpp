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

Vector::Vector(const Vector &other)
{
    data_ = other.data_;
}

// Vector::Vector(const Matrix &other)
// {
//     // check if the matrix is a column vector or a row vector
//     if (other.cols() != 1 && other.rows() != 1)
//     {
//         throw std::invalid_argument("Matrix must be a column vector");
//     }

//     if (other.cols() == 1)
//     {
//         // copy the data from the matrix to the vector
//         data_ = std::vector<double>(other.rows());
//         for (size_t i = 0; i < other.rows(); ++i)
//         {
//             data_[i] = other(i, 0);
//         }
//     }
//     else
//     {
//         // copy the data from the matrix to the vector
//         data_ = std::vector<double>(other.cols());
//         for (size_t i = 0; i < other.cols(); ++i)
//         {
//             data_[i] = other(0, i);
//         }
//     }
// }

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
    return data_.size();
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

Vector Vector::operator=(const Vector &other)
{
    // check if the two vectors have the same size
    if (data_.size() != other.data_.size())
    {
        throw std::invalid_argument("Vectors must have the same size");
    }

    // assign the values of the other vector to this vector
    for (size_t i = 0; i < data_.size(); ++i)
    {
        data_[i] = other[i];
    }

    return *this;
}

bool Vector::operator==(const Vector &other) const
{
    // check if the two vectors have the same size
    if (data_.size() != other.data_.size())
    {
        throw std::invalid_argument("Vectors must have the same size");
    }

    // compare the two vectors element-wise
    for (size_t i = 0; i < data_.size(); ++i)
    {
        if (data_[i] != other[i])
        {
            return false;
        }
    }
    return true;
}

bool Vector::operator!=(const Vector &other) const
{
    return !(*this == other);
}

Vector Vector::operator*(const Matrix &matrix) const
{
    // check if the size of the vector is equal to the number of rows in the matrix
    if (data_.size() != matrix.rows())
    {
        throw std::invalid_argument("The number of rows in the matrix must be equal to the size of the vector");
    }

    // create a new vector to store the result
    Vector result(matrix.cols());

    // multiply the vector by the matrix
    for (size_t i = 0; i < matrix.cols(); ++i)
    {
        for (size_t j = 0; j < matrix.rows(); ++j)
        {
            result[i] += data_[j] * matrix(j, i);
        }
    }

    return result;
}

Vector Vector::operator*(double scalar) const
{
    // create a new vector to store the result
    Vector result(data_.size());

    // multiply the vector by the scalar
    for (size_t i = 0; i < data_.size(); ++i)
    {
        result[i] = data_[i] * scalar;
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

std::ostream &operator<<(std::ostream &os, const Vector &vector)
{
    os << "[";
    for (size_t i = 0; i < vector.size(); ++i)
    {
        os << vector[i];
        if (i < vector.size() - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
