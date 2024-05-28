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
    virtual ~Activation() = default;

    [[nodiscard]] virtual double call(double x) const = 0;
    [[nodiscard]] virtual double derivative(double x) const = 0;
};

class ReLU_ final : public Activation
{
public:
    [[nodiscard]] double call(const double x) const override
    {
        return relu(x);
    }
    [[nodiscard]] double derivative(const double x) const override
    {
        return relu_derivative(x);
    }
};

class Sigmoid_ final : public Activation
{
public:
    [[nodiscard]] double call(const double x) const override
    {
        return sigmoid(x);
    }
    [[nodiscard]] double derivative(const double x) const override
    {
        return sigmoid_derivative(x);
    }
};

class Tanh_ final : public Activation
{
public:
    [[nodiscard]] double call(const double x) const override
    {
        return tanh_(x);
    }
    [[nodiscard]] double derivative(const double x) const override
    {
        return tanh_derivative(x);
    }
};

class Identity_ final : public Activation
{
public:
    [[nodiscard]] double call(const double x) const override
    {
        return identity(x);
    }
    [[nodiscard]] double derivative(const double x) const override
    {
        return identity_derivative(x);
    }
};

class Functions
{
public:
    Functions() = default;
    ~Functions() {
        // deleting the singletons
        delete ReLU;
        delete Sigmoid;
        delete Tanh;
        delete Identity;
    };

    static Activation *ReLU;
    static Activation *Sigmoid;
    static Activation *Tanh;
    static Activation *Identity;
};

#endif // ACTIVATION_H
