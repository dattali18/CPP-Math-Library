// vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

class Vector {
public:
    // CTORs
    Vector(size_t size);
    Vector(const std::vector<double>& data);

    // Accessors
    double& operator[](size_t index);
    const double& operator[](size_t index) const;

    // Methods
    size_t size() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;

    double dot(const Vector& other) const;
private:
    std::vector<double> data_;
};

#endif // VECTOR_H
