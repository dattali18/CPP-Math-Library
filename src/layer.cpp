#include "layer.h"
#include "vector.h"

#include <random>
#include <iostream>

Layer::Layer(size_t input_size, size_t output_size)
    : weights_(output_size, input_size), biases_(output_size), last_input_(input_size), last_output_(output_size){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    for (size_t i = 0; i < output_size; ++i) {
        for (size_t j = 0; j < input_size; ++j) {
            weights_(i, j) = dis(gen);
        }
        biases_[i] = dis(gen);
    }
}

Vector Layer::forward(const Vector &input)
{
    last_input_ = input;
    std::cout << "weights_: " << weights_.cols() << ", " << weights_.rows() <<  std::endl;
    std::cout << "input: " << input.size() << std::endl;
    last_output_ = (weights_ * input) + biases_;
    for (size_t i = 0; i < last_output_.size(); ++i) {
        last_output_[i] = tanh(last_output_[i]);
    }
    return last_output_;
}

void Layer::backward(const Vector& grad, double learning_rate) {
    Vector d_output = grad;
    for (size_t i = 0; i < d_output.size(); ++i) {
        d_output[i] *= tanh_derivative(last_output_[i]);
    }

    for (size_t i = 0; i < weights_.rows(); ++i) {
        for (size_t j = 0; j < weights_.cols(); ++j) {
            weights_(i, j) -= learning_rate * d_output[i] * last_input_[j];
        }
        biases_[i] -= learning_rate * d_output[i];
    }
}
