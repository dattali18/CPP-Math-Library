#include "neural_network.h"
#include "vector.h"

#include <cassert>
#include <iostream>

// this is the test file for the neural network class
void test_simple_nn() {
    // using the builder class to create a simple neural network
    NeuralNetwork nn = NeuralNetwork::Builder()
        .set_layers(2, 1, {32})
        .set_activations_function({Functions::Tanh, Functions::Tanh, Functions::Identity})
        .set_loss_function(Loss::LOG_LOSS)
        .build();

    const std::vector inputs = {
        Vector({0, 0}),
        Vector({1, 0}),
        Vector({0, 1}),
        Vector({1, 1}),
    };

    const std::vector outputs = {
        Vector({0}),
        Vector({1}),
        Vector({1}),
        Vector({1}),
    };

    nn.train(inputs, outputs, 10000, 0.01);

    // for (int i = 0; i < outputs.size(); i++) {
    //     Vector output = nn.predict(inputs[i]);
    //     assert(output.size() == 1);
    // }

    // print the ouput against the expected output
    for (int i = 0; i < outputs.size(); i++) {
        Vector output = nn.predict(inputs[i]);
        std::cout << "Expected: " << outputs[i] << " Got: " << output << std::endl;
    }
}

int main() {
    test_simple_nn();
    return 0;
}