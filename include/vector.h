// vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cstddef>

#include <iostream>

#include <matrix.h>

class Matrix;

class Vector
{
public:
    // CTORs
    explicit Vector(size_t size);

    explicit Vector(const std::vector<double> &data);

    Vector(const std::initializer_list<double> init_list) : data_(init_list) {}

    Vector(const Vector &other);

    // Methods
    [[nodiscard]] size_t size() const;

    // methods to get the Matrix form of the vector
    [[nodiscard]] Matrix toRowMatrix() const;
    [[nodiscard]] Matrix toColumnMatrix() const;

    // Accessors
    double &operator[](size_t index);
    const double &operator[](size_t index) const;

    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    Vector operator*(const Matrix &matrix) const;

    Vector operator*(double scalar) const;

    // Overloading
    Vector operator=(const Vector &other);

    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;

    bool operator<(double scalar) const;
    bool operator>(double scalar) const;

    [[nodiscard]] double dot(const Vector &other) const;

    // overloading the << operator to print the vector
    friend std::ostream &operator<<(std::ostream &os, const Vector &vector);

private:
    std::vector<double> data_;
};

#endif // VECTOR_H
