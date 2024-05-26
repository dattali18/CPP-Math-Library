// matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

#include <vector.h>

class Matrix {
    public:
        // CTORs
        Matrix(size_t rows, size_t cols);
        Matrix(const std::vector<std::vector<double>>& data);

        // CTORs
        // receive a vector and create a matrix
        Matrix(const Vector& vec);

        // Accessors
        double& operator()(size_t row, size_t col);
        const double& operator()(size_t row, size_t col) const;

        // Methods
        size_t rows() const;
        size_t cols() const;

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;

        // Operator overloading for scalar multiplication
        Matrix operator*(double scalar) const;

        // Matrix multiplication
        Matrix operator*(const Matrix& other) const;
        Matrix mult(const Matrix& other) const;

        Matrix transpose() const;
        Matrix t() const;

    private:
        std::vector<std::vector<double>> data_;
};

#endif // MATRIX_H