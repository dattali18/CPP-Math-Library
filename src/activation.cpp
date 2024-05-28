#include "activation.h"

#include <vector>
#include <cmath>

/// @brief  Rectified Linear Unit (ReLU) activation function
/// @param x  input
/// @return  output
double relu(const double x)
{
    return x > 0 ? x : 0;
}

/// @brief  Derivative of the Rectified Linear Unit (ReLU) activation function
/// @param x  input
/// @return  output
double relu_derivative(const double x)
{
    return x > 0 ? 1 : 0;
}

/// @brief  Sigmoid activation function
/// @param x  input
/// @return  output
double sigmoid(const double x)
{
    return 1 / (1 + exp(-x));
}

/// @brief  Derivative of the Sigmoid activation function
/// @param x  input
/// @return  output
double sigmoid_derivative(const double x)
{
    return sigmoid(x) * (1 - sigmoid(x));
}

/// @brief  Hyperbolic Tangent (tanh) activation function
/// @param x  input
/// @return  output
double tanh_(const double x)
{
    return std::tanh(x);
}

/// @brief  Derivative of the Hyperbolic Tangent (tanh) activation function
/// @param x  input
/// @return output
double tanh_derivative(const double x)
{
    return 1 - std::pow(tanh(x), 2);
}

double softmax(const std::vector<double> &x, const size_t i)
{
    double sum = 0;
    for (size_t j = 0; j < x.size(); j++)
    {
        sum += exp(x[j]);
    }
    return exp(x[i]) / sum;
}

double softmax_derivative(const std::vector<double> &x, const size_t i)
{
    return softmax(x, i) * (1 - softmax(x, i));
}

double identity(const double x)
{
    return x;
}

double identity_derivative(const double x)
{
    return 1;
}

Activation *Functions::ReLU = new ReLU_();
Activation *Functions::Sigmoid = new Sigmoid_();
Activation *Functions::Tanh = new Tanh_();
Activation *Functions::Identity = new Identity_();