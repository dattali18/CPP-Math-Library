#include <iostream>

#include "vector.h"
#include "layer.h"
#include "activation.h"
#include "neural_network.h"
#include "loss.h"

// Test function for a network with no hidden layer
void test_no_hidden_layer()
{
    try
    {
        // Define input and output size
        size_t input_size = 2;
        size_t output_size = 1;

        // Create NNBuilder and set up the network
        NNBuilder builder;
        builder = builder
                      .set_input_layer(input_size)
                      .set_ouput_layer(output_size)
                      .set_activation_function({Functions::Sigmoid})
                      .set_loss_function(Loss::MSE);

        // Build the NN
        NN nn = builder.build();

        // Training data
        std::vector<Vector> X_train = {
            Vector({0.0, 0.0}),
            Vector({0.0, 1.0}),
            Vector({1.0, 0.0}),
            Vector({1.0, 1.0})};

        std::vector<Vector> y_train = {
            Vector({0.0}),
            Vector({1.0}),
            Vector({1.0}),
            Vector({0.0})};

        // Train the NN
        nn.fit(X_train, y_train, 1000, 0.1);

        // Test the NN
        for (const auto &input : X_train)
        {
            Vector output = nn.predict(input);
            std::cout << "Input: " << input << " Output: " << output << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

// Test function for a network with one hidden layer
void test_simple_hidden_layer()
{
    try
    {
        // Define input, hidden, and output size
        size_t input_size = 2;
        size_t hidden_size = 3;
        size_t output_size = 1;

        // Create NNBuilder and set up the network
        NNBuilder builder;
        builder = builder
                      .set_input_layer(input_size)
                      .set_hidden_layer({hidden_size})
                      .set_ouput_layer(output_size)
                      .set_activation_function({Functions::Sigmoid, Functions::Sigmoid})
                      .set_loss_function(Loss::MSE);

        // Build the NN
        NN nn = builder.build();

        // Training data
        std::vector<Vector> X_train = {
            Vector({0.0, 0.0}),
            Vector({0.0, 1.0}),
            Vector({1.0, 0.0}),
            Vector({1.0, 1.0})};

        std::vector<Vector> y_train = {
            Vector({0.0}),
            Vector({1.0}),
            Vector({1.0}),
            Vector({0.0})};

        // Train the NN
        nn.fit(X_train, y_train, 1000, 0.1);

        // Test the NN
        for (const auto &input : X_train)
        {
            Vector output = nn.predict(input);
            std::cout << "Input: " << input << " Output: " << output << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Testing NN with no hidden layer:" << std::endl;
    test_no_hidden_layer();

    std::cout << "\nTesting NN with one hidden layer:" << std::endl;
    test_simple_hidden_layer();

    return 0;
}
