// matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstddef>

#include <vector.h>

class Vector;

class Matrix {
    public:
        // CTORs
        Matrix(size_t rows, size_t cols);
        Matrix(const std::vector<std::vector<double>>& data);

        // CTORs
        Matrix(const Vector& vec);

        // Methods
        size_t rows() const;
        size_t cols() const;

        Vector row(size_t row) const;
        Vector col(size_t col) const;

        // Accessors
        double& operator()(size_t row, size_t col);
        const double& operator()(size_t row, size_t col) const;

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;

        // Operator overloading for scalar multiplication
        Matrix operator*(double scalar) const;

        // Matrix multiplication
        Matrix operator*(const Matrix& other) const;
        Matrix mult(const Matrix& other) const;

        // Matrix-vector multiplication
        Vector operator*(const Vector& vec) const;

        // ouput stream
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        

        Matrix transpose() const;
        Matrix T() const;

    private:
        std::vector<std::vector<double>> data_;
};

#endif // MATRIX_H

// Path: include/vector.h