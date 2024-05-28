#include "neural_network.h"

#include <vector>

void NN::set_layers(std::vector<size_t> sequential)
{
    layers_.clear();
    // take each pair of number in sequential_ and create a layer
    // and add it to the layers_ vector
    for (size_t i = 0; i < sequential.size() - 1; i++)
    {
        layers_.emplace_back(Layer(sequential[i], sequential[i + 1]));
    }
}

void NN::set_activation_function(std::vector<Activation *> activation_functions)
{
    // set the activation function for each layer
    for (size_t i = 0; i < layers_.size() - 1; i++)
    {
        layers_[i].set_activation(activation_functions[i]);
    }
    // the activation function for the output layer
    layers_.back().set_activation(Functions::Identity);
}

void NN::set_loss_function(LossFunction *loss_function)
{
    loss_function_ = loss_function;
}

void NN::forward_propagation(const Vector &input)
{
    // perform forward propagation
    Vector output = input;
    for (size_t i = 0; i < layers_.size(); i++)
    {
        output = layers_[i].forward(output);
    }
    output_ = output;
}

void NN::backward_propagation(const Vector &y, double learning_rate)
{
    // perform backward propagation
    Vector grad = loss_function_->call(output_, y);
    for (int i = layers_.size() - 1; i >= 0; i--)
    {
        grad = layers_[i].backward(grad, learning_rate);
    }
}

void NN::fit(std::vector<Vector> X_train, std::vector<Vector> y_train, size_t epochs, double learning_rate)
{
    for (size_t epoch = 0; epoch < epochs; ++epoch)
    {
        for (size_t i = 0; i < X_train.size(); ++i)
        {
            forward_propagation(X_train[i]);
            // backward_propagation(y_train[i], learning_rate);
        }
    }
}

void NN::test(std::vector<Vector> X_test, std::vector<Vector> y_test)
{
    double total_loss = 0.0;
    for (size_t i = 0; i < X_test.size(); ++i)
    {
        forward_propagation(X_test[i]);
        total_loss += loss_function_->call(output_, y_test[i]);
    }
    std::cout << "Average Loss: " << total_loss / X_test.size() << std::endl;
}

Vector NN::predict(const Vector &input)
{
    forward_propagation(input);
    return output_;
}

// /*
// void test_train_layer()
// {
//     Layer layer(3, 2);
//     layer.set_activation(Functions::ReLU);

//     Vector input({1.0, 2.0, 3.0});
//     Vector target({0.1, 0.2});

//     double learning_rate = 0.01;
//     size_t epochs = 1000;

//     for (size_t i = 0; i < epochs; ++i)
//     {
//         Vector output = layer.forward(input);
//         Vector loss = output - target;
//         Vector grad = loss * 2;
//         layer.backward(grad, learning_rate);
//     }
//     std::cout << "Training completed." << std::endl;
//     std::cout << "Final Result: " << layer.forward(input) << std::endl;

//     assert(layer.forward(input) - target < 1e-6);
// }
// */