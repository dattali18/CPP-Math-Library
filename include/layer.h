#ifndef LAYER_H
#define LAYER_H

#include <cstddef>

#include "matrix.h"
#include "vector.h"
#include "activation.h"

class Activation;

class Layer
{
public:
    Layer(size_t input_size, size_t output_size);

    Vector forward(const Vector &input);
    void backward(const Vector &grad, double learning_rate=0.01);

    const Matrix &weights() const { return weights_; }
    const Vector &biases() const { return biases_; }

    const Vector &last_input() const { return last_input_; }
    const Vector &last_output() const { return last_output_; }

    void set_weights(const Matrix &weights) { weights_ = weights; }
    void set_biases(const Vector &biases) { biases_ = biases; }
    void set_activation(Activation *activation) { activation_ = activation; }

    Vector get_last_ouput() { return last_output_; }

private:
    Matrix weights_;
    Vector biases_;
    Vector last_input_;
    Vector last_output_;

    Activation *activation_;
};

#endif // LAYER_H
