// vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cstddef>

#include <iostream>

#include <matrix.h>

class Matrix;


class Vector {
public:
    // CTORs
    Vector(size_t size);
    Vector(const std::vector<double>& data);
    Vector(const Vector& other);

    // Accessors
    double& operator[](size_t index);
    const double& operator[](size_t index) const;

    // Methods
    size_t size() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;

    // Overloading
    Vector operator=(const Vector& other);

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    Vector operator*(const Matrix& matrix) const;

    Vector operator*(double scalar) const;

    double dot(const Vector& other) const;

    // overloading the << operator to print the vector
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
    
private:
    std::vector<double> data_;
};

#endif // VECTOR_H
