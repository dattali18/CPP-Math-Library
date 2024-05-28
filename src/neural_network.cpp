#include "neural_network.h"


NeuralNetwork::NeuralNetwork(): layers_(), loss_(), activations_(){}

NeuralNetwork::NeuralNetwork(const NeuralNetwork::Builder &builder):
    layers_(builder.layers_),
    loss_(builder.loss_),
    activations_(builder.activations_) {}

void NeuralNetwork::train(const std::vector<Vector> &inputes, const std::vector<Vector> &targets, const size_t epochs,
                          const double learning_rate=0.01) {
    for (size_t epoch = 0; epoch < epochs; ++epoch) {
        for (size_t i = 0; i < inputes.size(); ++i) {
            const Vector &input = inputes[i];
            const Vector &target = targets[i];
            std::vector<Vector> outputs;
            outputs.reserve(layers_.size());
            Vector output = input;
            outputs.push_back(output);
            for (size_t j = 0; j < layers_.size(); ++j) {
                output = layers_[j].forward(output);
                outputs.push_back(output);
            }
            const size_t size = layers_.size();
            Vector loss_gradient = loss_->gradient(output, target);
            for (size_t j = size - 1; j > 0; --j) {
                loss_gradient = layers_[j].backward(loss_gradient, outputs[j], outputs[j + 1], learning_rate);
            }
        }
    }
}

Vector NeuralNetwork::forward(const Vector &input) {
    Vector output = input;
    for (size_t i = 0; i < layers_.size(); ++i) {
        output = layers_[i].forward(output);
    }
    return output;
}

Vector NeuralNetwork::predict(const Vector &input) {
    // return the input after passing through the network
    return forward(input);
}
