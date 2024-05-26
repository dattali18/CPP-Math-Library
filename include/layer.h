#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"
#include "vector.h"
#include "activation.h"

class Layer {
public:
    Layer(size_t input_size, size_t output_size);
    Vector forward(const Vector& input);
    void backward(const Vector& grad, double learning_rate);
private:
    Matrix weights_;
    Vector biases_;
    Vector last_input_;
    Vector last_output_;
};

#endif // LAYER_H
