#include "matrix.h"

#include <stdexcept>
#include <format>
#include <vector>

Matrix::Matrix(size_t rows, size_t cols)
{
    // Initialize the matrix with zeros
    data_ = std::vector<std::vector<double>>(rows, std::vector<double>(cols, 0.0));
}

Matrix::Matrix(const std::vector<std::vector<double>> &data)
{
    data_ = data;
}

Matrix::Matrix(const Vector &vec)
{
    data_ = std::vector<std::vector<double>>(vec.size(), std::vector<double>(1, 0.0));
    for (size_t i = 0; i < vec.size(); ++i)
    {
        data_[i][0] = vec[i];
    }
}

double &Matrix::operator()(size_t row, size_t col)
{
    return data_[row][col];
}

const double &Matrix::operator()(size_t row, size_t col) const
{
    return data_[row][col];
}

size_t Matrix::rows() const
{
    return data_.size();
}

size_t Matrix::cols() const
{
    return data_[0].size();
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (rows() != other.rows() || cols() != other.cols())
    {
        throw std::invalid_argument(std::format("Matrices must have the same dimensions for addition. {}x{} != {}x{}", rows(), cols(), other.rows(), other.cols()));
    }

    Matrix result(rows(), cols());
    for (size_t i = 0; i < rows(); ++i)
    {
        for (size_t j = 0; j < cols(); ++j)
        {
            result(i, j) = data_[i][j] + other(i, j);
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    if (rows() != other.rows() || cols() != other.cols())
    {
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
    }

    Matrix result(rows(), cols());
    for (size_t i = 0; i < rows(); ++i)
    {
        for (size_t j = 0; j < cols(); ++j)
        {
            result(i, j) = data_[i][j] - other(i, j);
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    if (cols() != other.rows())
    {
        // throw an exception if the number of columns in the first matrix does not match the number
        // of rows in the second matrix and explain the difference of dimensions
        throw std::invalid_argument("Dimensions mismatch for matrix multiplication.");
    }

    Matrix result(rows(), other.cols());
    for (size_t i = 0; i < rows(); ++i)
    {
        for (size_t j = 0; j < other.cols(); ++j)
        {
            for (size_t k = 0; k < cols(); ++k)
            {
                result(i, j) += data_[i][k] * other(k, j);
            }
        }
    }

    return result;
}

Matrix Matrix::mult(const Matrix &other) const
{
    return operator*(other);
}

Vector Matrix::operator*(const Vector &vec) const
{
    if (cols() != vec.size())
    {
        throw std::invalid_argument("The number of columns in the matrix must be equal to the size of the vector");
    }

    Vector result(rows());
    for (size_t i = 0; i < rows(); ++i)
    {
        for (size_t j = 0; j < cols(); ++j)
        {
            result[i] += data_[i][j] * vec[j];
        }
    }

    return result;
}

Matrix Matrix::operator*(double scalar) const
{
    Matrix result(rows(), cols());
    for (size_t i = 0; i < rows(); ++i)
    {
        for (size_t j = 0; j < cols(); ++j)
        {
            result(i, j) = data_[i][j] * scalar;
        }
    }

    return result;
}

Matrix Matrix::transpose() const
{
    Matrix result(cols(), rows());
    for (size_t i = 0; i < rows(); ++i)
    {
        for (size_t j = 0; j < cols(); ++j)
        {
            result(j, i) = data_[i][j];
        }
    }

    return result;
}

Matrix Matrix::T() const
{
    return transpose();
}

// Path: src/main.cpp
