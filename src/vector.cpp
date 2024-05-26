#include "vector.h"
#include <stdexcept>

/// @brief  ctor for the vector class
/// @param size  size of the vector
Vector::Vector(size_t size)
{
    // init a vector of size `size` with zeros
    data_ = std::vector<double>(size, 0.0);
}

/// @brief  ctor for the vector class
/// @param data  vector of doubles
Vector::Vector(const std::vector<double> &data)
{
    data_ = data;
}

/// @brief  ctor for the vector class
/// @param other  another vector
Vector::Vector(const Vector &other)
{
    data_ = other.data_;
}

/// @brief  return the vector as a row matrix
/// @return  the vector as a row matrix
Matrix Vector::toRowMatrix() const
{
    // create a new matrix with one row and the same number of columns as the vector
    Matrix result(*this);

    return result;
}

/// @brief  return the vector as a column matrix
/// @return  the vector as a column matrix
Matrix Vector::toColumnMatrix() const
{
    // create a new matrix with one column and the same number of rows as the vector
    Matrix result(*this);

    return result.T();
}

/// @brief  access the element at the given index
/// @param index  index
/// @return  the element at the given index
double &Vector::operator[](size_t index)
{
    return data_[index];
}

/// @brief  access the element at the given index
/// @param index  index
/// @return  the element at the given index
const double &Vector::operator[](size_t index) const
{
    return data_[index];
}

/// @brief  return the size of the vector
/// @return  the size of the vector
size_t Vector::size() const
{
    return data_.size();
}

/// @brief  add two vectors
/// @param other  another vector
/// @return  the sum of the two vectors
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

/// @brief  subtract two vectors
/// @param other  another vector
/// @return  the difference of the two vectors
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

/// @brief  assign the values of another vector to this vector
/// @param other  another vector
/// @return  this vector
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

/// @brief  compare two vectors for equality
/// @param other  another vector
/// @return  true if the two vectors are equal, false otherwise
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

/// @brief  compare two vectors for inequality
/// @param other  another vector
/// @return  true if the two vectors are not equal, false otherwise
bool Vector::operator!=(const Vector &other) const
{
    return !(*this == other);
}

/// @brief  matrix-vector multiplication
/// @param matrix  matrix to multiply with
/// @return  the result of the matrix-vector multiplication
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

/// @brief  operator overloading for scalar multiplication
/// @param scalar  scalar to multiply with
/// @return  the result of the scalar multiplication
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

/// @brief  compute the dot product of two vectors
/// @param other  another vector
/// @return  the dot product of the two vectors
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

/// @brief  compute the norm of the vector
/// @param os  output stream
/// @param vector  vector to output
/// @return  the output stream
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
