#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <vector>

// Activation functions for the hidden layers

double relu(double x);
double relu_derivative(double x);

double sigmoid(double x);
double sigmoid_derivative(double x);

double tanh_(double x);
double tanh_derivative(double x);

double identity(double x);
double identity_derivative(double x);

// Activation functions for the output layer

// softmax activation function
double softmax(std::vector<double> x, size_t i);
double softmax_derivative(std::vector<double> x, size_t i);



class Activation
{
public:
    virtual double call(double x) const = 0;
    virtual double derivative(double x) const = 0;
};

class ReLU_ : public Activation
{
public:
    double call(double x) const override
    {
        return relu(x);
    }
    double derivative(double x) const override
    {
        return relu_derivative(x);
    }
};

class Sigmoid_ : public Activation
{
public:
    double call(double x) const override
    {
        return sigmoid(x);
    }
    double derivative(double x) const override
    {
        return sigmoid_derivative(x);
    }
};

class Tanh_ : public Activation
{
public:
    double call(double x) const override
    {
        return tanh_(x);
    }
    double derivative(double x) const override
    {
        return tanh_derivative(x);
    }
};

class Identity_ : public Activation
{
public:
    double call(double x) const override
    {
        return identity(x);
    }
    double derivative(double x) const override
    {
        return identity_derivative(x);
    }
};

class Functions
{
public:
    static Activation *ReLU;
    static Activation *Sigmoid;
    static Activation *Tanh;
    static Activation *Identity;
};

#endif // ACTIVATION_H
