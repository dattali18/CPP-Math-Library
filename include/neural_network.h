// neural_network.h
// Version: 1.0
// Date: 2021-06-08
#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>

#include "activation.h"
#include "layer.h"
#include "loss.h"
#include "vector.h"

class NeuralNetwork final {
public:
    class Builder;

    NeuralNetwork(const NeuralNetwork &) = delete;

    NeuralNetwork();

    explicit NeuralNetwork(const NeuralNetwork::Builder & builder);;

    ~NeuralNetwork() = default;

    // Mark: - Public Methods
    void train(const std::vector<Vector> &inputes, const std::vector<Vector> &targets, size_t epochs, double learning_rate);

    // forward method
    [[nodiscard]] Vector forward(const Vector &input);

    // predict method
    [[nodiscard]] Vector predict(const Vector &input);

    // this nerual network will require the a Builder class to facilitate the construction of the network
    class Builder final {
    public:
        Builder() = default;
        ~Builder() = default;

        // setting up the method to build the neural network
        [[nodiscard]] NeuralNetwork build() {
            // setup the neural network

            // check if the network is valid
            if(layers_.empty()) {
                throw std::runtime_error("No layers in the network");
            }

            if(activations_.empty())
                throw std::runtime_error("No activation functions in the network");

            if(loss_ == nullptr)
                throw std::runtime_error("No loss function in the network");

            // put in the activation functions into the layers
            for (size_t i = 0; i < activations_.size(); ++i) {
                layers_[i].set_activation(activations_[i]);
            }
            return NeuralNetwork(*this);
        }

        // setting up the number of layers by taking in input ouput and hidden layers
        Builder &set_layers(const size_t input, const size_t output, const std::vector<size_t> &hidden_layers) {
            layers_.emplace_back(input, hidden_layers[0]);
            for (size_t i = 1; i < hidden_layers.size(); ++i) {
                layers_.emplace_back(hidden_layers[i - 1], hidden_layers[i]);
            }
            layers_.emplace_back(hidden_layers.back(), output);
            return *this;
        }

        Builder &set_loss_function(const LossFunction *loss_function) {
            loss_ = loss_function;
            return *this;
        }

        Builder &set_activations_function(const std::vector<Activation*> &activations) {
            activations_ = activations;
            return *this;
        }

        std::vector<Layer> layers_;
        const LossFunction *loss_{};
        std::vector<Activation*> activations_;
    };

private:
    std::vector<Layer> layers_;
    const LossFunction *loss_;
    std::vector<Activation *> activations_;
};

#endif // NEURAL_NETWORK_H