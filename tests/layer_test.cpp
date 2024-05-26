#include "layer.h"
#include "vector.h"

#include <cassert>
#include <iostream>

void test_layer_forward() {
    Layer layer(3, 2);
    Vector input({1.0, 2.0, 3.0});
    std::cout << "input: " << input << std::endl;
    Vector output = layer.forward(input);
    
    // Here we simply print the output as we don't know the exact values due to random initialization
    // std::cout << "Forward pass output: ";
    for (size_t i = 0; i < output.size(); ++i) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
    
    assert(output.size() == 2);
}

void test_layer_backward() {
    Layer layer(3, 2);
    Vector input({1.0, 2.0, 3.0});
    layer.forward(input);
    
    Vector grad(std::vector<double>{0.1, 0.2});
    layer.backward(grad, 0.01);

    // Since backward modifies weights and biases, we should test if they are modified correctly
    // This simple test will not cover correctness as weights and biases are initialized randomly
    // You might want to add more comprehensive tests for checking weight updates
    // std::cout << "Backward pass completed." << std::endl;
}

void test_train_layer() {
    Layer layer(3, 2);
    layer.set_activation(Functions::ReLU);

    Vector input({1.0, 2.0, 3.0});
    Vector target({0.1, 0.2});

    double learning_rate = 0.01;
    size_t epochs = 1000;

    for (size_t i = 0; i < epochs; ++i) {
        Vector output = layer.forward(input);
        Vector loss = output - target;
        Vector grad = loss * 2;
        layer.backward(grad, learning_rate);
    }
    std::cout << "Training completed." << std::endl;
    std::cout << "Final Result: " << layer.forward(input)  << std::endl;

    assert(layer.forward(input) - target < 1e-6);
}

int main() {
    test_layer_forward();
    test_layer_backward();
    test_train_layer();

    return 0;
}
