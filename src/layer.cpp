#include "layer.h"
#include "vector.h"

#include <random>
#include <iostream>

/// @brief  ctor for the Layer class
/// @param input_size  size of the input
/// @param output_size  size of the output
Layer::Layer(size_t input_size, size_t output_size)
    : weights_(output_size, input_size), biases_(output_size), last_input_(input_size), last_output_(output_size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    for (size_t i = 0; i < output_size; ++i)
    {
        for (size_t j = 0; j < input_size; ++j)
        {
            weights_(i, j) = dis(gen);
        }
        biases_[i] = dis(gen);
    }

    // default activation function is sigmoid
    activation_ = Functions::Sigmoid;
}

/// @brief  forward pass
/// @param input  input to the layer
/// @return  output of the layer
Vector Layer::forward(const Vector &input)
{
    last_input_ = input;
    last_output_ = (weights_ * input) + biases_;
    for (size_t i = 0; i < last_output_.size(); ++i)
    {
        last_output_[i] = activation_->call(last_output_[i]);
    }
    return last_output_;
}

/// @brief  backward pass
/// @param grad  gradient of the loss with respect to the output
/// @param learning_rate  learning rate
void Layer::backward(const Vector &grad, double learning_rate)
{
    Vector d_output = grad;
    for (size_t i = 0; i < d_output.size(); ++i)
    {
        d_output[i] *= activation_->derivative(last_output_[i]);
    }

    for (size_t i = 0; i < weights_.rows(); ++i)
    {
        for (size_t j = 0; j < weights_.cols(); ++j)
        {
            weights_(i, j) -= learning_rate * d_output[i] * last_input_[j];
        }
        biases_[i] -= learning_rate * d_output[i];
    }
}
