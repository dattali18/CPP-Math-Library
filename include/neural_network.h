// neural_network.h
#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "layer.h"
#include "activation.h"
#include "vector.h"
#include "loss.h"

#include <vector>

/*
this class will represent the neural network
it will have a list of layers and will be able to
perform forward and backward propagation
and a fit method to train the network
and predict method to predict the output
using the a Builder class to build the network
*/

class NN
{
public:
    NN() : layers_({}), input_({}), output_({}), loss_function_(Loss::MSE){};

    void set_layers(std::vector<size_t> sequential);

    void set_activation_function(std::vector<Activation *> activation_functions);

    void set_loss_function(LossFunction *loss_function);

    void forward_propagation(const Vector &input);

    void backward_propagation(const Vector &y, double learning_rate = 0.01);

    void fit(std::vector<Vector> X_train, std::vector<Vector> y_train, size_t epochs, double learning_rate);

    void test(std::vector<Vector> X_test, std::vector<Vector> y_test);

    Vector predict(const Vector &input);

private:
    // list of layers
    std::vector<Layer> layers_;

    // overall input_ ouput_ and error_
    Vector input_;
    Vector output_;

    // loss function
    LossFunction *loss_function_;
};

// a builder class for the NN class that will build the neural network
class NNBuilder
{
public:
    NNBuilder() : sequential_({}), activation_functions_({}), loss_function_(nullptr){};

    NNBuilder(size_t input, size_t ouput) : sequential_({})
    {
        // add input and output layer {input, output}
        sequential_.push_back(input);
        sequential_.push_back(ouput);
    }

    NNBuilder *set_input_layer(size_t input)
    {
        // put the input layer at the beginning of the sequential_ vector
        sequential_.insert(sequential_.begin(), input);
        return this;
    };

    NNBuilder *set_ouput_layer(size_t ouput)
    {
        sequential_.push_back(ouput);
        return this;
    }

    NNBuilder *set_hidden_layer(std::vector<size_t> hidden)
    {
        for (size_t i = 0; i < hidden.size(); i++)
        {
            sequential_.push_back(hidden[i]);
        }
        return this;
    }

    NNBuilder *set_activation_function(std::vector<Activation *> activation_functions)
    {
        // set the activation functions for each layer
        activation_functions_ = activation_functions;
        return this;
    }

    NNBuilder *set_loss_function(LossFunction *loss_function)
    {
        loss_function_ = loss_function;
        return this;
    }

    NN build()
    {
        // check if the network is valid
        // i.e. input layer, output layer and at least one hidden layer
        if (sequential_.size() < 3)
        {
            throw std::invalid_argument("Invalid network configuration");
        }
        // check if the number of activation functions is equal to the number of layers - 1
        if (activation_functions_.size() != sequential_.size() - 1)
        {
            throw std::invalid_argument("Invalid number of activation functions");
        }
        // check if the loss function is set
        if (loss_function_ == nullptr)
        {
            throw std::invalid_argument("Loss function not set");
        }
        // create the network
        NN nn;
        nn.set_layers(sequential_);
        nn.set_activation_function(activation_functions_);
        nn.set_loss_function(loss_function_);
        return nn;
    }

private:
    std::vector<size_t>
        sequential_;

    std::vector<Activation *> activation_functions_;

    LossFunction *loss_function_;
};

#endif // NEURAL_NETWORk_H
