#include "activation.h"

#include <cmath>

/// @brief  Rectified Linear Unit (ReLU) activation function
/// @param x  input
/// @return  output
double relu(double x)
{
    return x > 0 ? x : 0;
}

/// @brief  Derivative of the Rectified Linear Unit (ReLU) activation function
/// @param x  input
/// @return  output
double relu_derivative(double x)
{
    return x > 0 ? 1 : 0;
}

/// @brief  Sigmoid activation function
/// @param x  input
/// @return  output
double sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}

/// @brief  Derivative of the Sigmoid activation function
/// @param x  input
/// @return  output
double sigmoid_derivative(double x)
{
    return sigmoid(x) * (1 - sigmoid(x));
}

/// @brief  Hyperbolic Tangent (tanh) activation function
/// @param x  input
/// @return  output
double tanh_(double x)
{
    return std::tanh(x);
}

/// @brief  Derivative of the Hyperbolic Tangent (tanh) activation function
/// @param x  input
/// @return output
double tanh_derivative(double x)
{
    return 1 - std::pow(tanh(x), 2);
}

Activation *Functions::ReLU = new ReLU_();
Activation *Functions::Sigmoid = new Sigmoid_();
Activation *Functions::Tanh = new Tanh_();