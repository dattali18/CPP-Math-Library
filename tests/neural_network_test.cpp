#include <iostream>

#include "neural_network.h"
#include "activation.h"
#include "loss.h"

void test_no_hidden_layer()
{
    // // Define input and output size
    // size_t input_size = 2;
    // size_t output_size = 1;

    // // Create NNBuilder and set up the network
    // NNBuilder *builder = new NNBuilder(input_size, output_size);
    // builder->set_activation_function({Functions::Sigmoid});
    // builder->set_loss_function(Loss::MSE);

    // // Build the NN
    // NN nn = builder->build();

    // // Training data
    // std::vector<Vector> X_train = {Vector({0.0, 0.0}), Vector({0.0, 1.0}), Vector({1.0, 0.0}), Vector({1.0, 1.0})};
    // std::vector<Vector> y_train = {Vector({0.0}), Vector({1.0}), Vector({1.0}), Vector({0.0})};

    // // Train the NN
    // nn.fit(X_train, y_train, 1000, 0.1);

    // // Test the NN
    // for (const auto &input : X_train)
    // {
    //     Vector output = nn.predict(input);
    //     std::cout << "Input: " << input << " Output: " << output << std::endl;
    // }
}

int main()
{
    test_no_hidden_layer();
    return 0;
}