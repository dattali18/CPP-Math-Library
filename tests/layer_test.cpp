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
    std::cout << "Forward pass output: ";
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
    std::cout << "Backward pass completed." << std::endl;
}

int main() {
    test_layer_forward();
    test_layer_backward();
    return 0;
}
