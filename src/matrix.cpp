#include "matrix.h"

#include <stdexcept>
#include <format>
#include <vector>

// [MARK] Ctor

/// @brief ctor for the matrix class
/// @param rows number of rows
/// @param cols  number of columns
Matrix::Matrix(const size_t rows, const size_t cols): cols_(cols) {
    // Initialize the matrix with zeros
    data_ = std::vector(rows, std::vector(cols, 0.0));
}

/// @brief ctor for the matrix class
/// @param data 2D vector of doubles
Matrix::Matrix(const std::vector<std::vector<double>> &data) : cols_({})
{
    data_ = data;
}

Matrix::Matrix(const Vector &vec) : cols_({})
{
    data_ = std::vector<std::vector<double>>(vec.size(), std::vector<double>(1, 0.0));
    for (size_t i = 0; i < vec.size(); ++i)
    {
        data_[i][0] = vec[i];
    }
}

// [MARK] Accessors

/// @brief access the element at the given row and column
/// @param row  row index
/// @param col  column index
/// @return  the element at the given row and column
double &Matrix::operator()(const size_t row, const size_t col)
{
    return data_[row][col];
}

/// @brief access the element at the given row and column
/// @param row  row index
/// @param col  column index
/// @return  the element at the given row and column
const double &Matrix::operator()(const size_t row, const size_t col) const
{
    return data_[row][col];
}


/**
 *
 * @return the number of rows and columns in the matrix
 */
size_t Matrix::rows() const
{
    return data_.size();
}

/**
 *
 * @return the number of columns in the matrix
 */
size_t Matrix::cols() const
{
    return data_[0].size();
}

// [MARK] Methods

/// @brief  get the row at the given index
/// @param row  row index
/// @return  the row at the given index
Vector Matrix::row(const size_t row) const
{
    return Vector(data_[row]);
}

/// @brief  get the column at the given index
/// @param col  column index
/// @return  the column at the given index
Vector Matrix::col(const size_t col) const
{
    std::vector<double> column;
    for (size_t i = 0; i < rows(); ++i)
    {
        column.push_back(data_[i][col]);
    }

    return Vector(column);
}

// [MARK] Operator overloading

/// @brief  matrix addition
/// @param other  matrix to add
/// @return  the result of the matrix addition
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

/// @brief  matrix subtraction
/// @param other  matrix to subtract
/// @return  the result of the matrix subtraction
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

/// @brief Matrix multiplication
/// @param other matrix to multiply with
/// @return the result of the matrix multiplication
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

/// @brief  matrix multiplication
/// @param other  matrix to multiply with
/// @return  the result of the matrix multiplication
Matrix Matrix::mult(const Matrix &other) const
{
    return operator*(other);
}

/// @brief  matrix-vector multiplication
/// @param vec  vector to multiply with
/// @return  the result of the matrix-vector multiplication
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

/// @brief  operator overloading for scalar multiplication
/// @param scalar  scalar to multiply with
/// @return  the result of the scalar multiplication
Matrix Matrix::operator*(const double scalar) const
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

/// @brief  matrix transpose
/// @return  the transpose of the matrix
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

/// @brief  matrix transpose
/// @return  the transpose of the matrix
Matrix Matrix::T() const
{
    return transpose();
}

/// @brief  main function
/// @param os  output stream
/// @param matrix  matrix to output
/// @return  the output stream
std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    os << "[";
    for (size_t i = 0; i < matrix.rows(); ++i)
    {
        for (size_t j = 0; j < matrix.cols(); ++j)
        {
            os << matrix(i, j) << " ";
        }
        os << std::endl;
    }
    os << "]";

    return os;
}

// Path: src/main.cpp