// neural_network.h
#ifdef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>

class NN
{
public:
};

// a builder class for the NN class that will build the neural network
class NNBuilder
{
public:
    NNBuilder() : sequential_({}){};

    NNBuilder(size_t input, size_t ouput) : sequential_({})
    {
        sequential_.push_back(input, 0);
        sequential_.push_back(ouput);
    }

    NNBuilder *set_input_layer(size_t input)
    {
        sequential_.push_back(input, 0);
        return this;
    };

    NNBuilder *set_ouput_layer(size_t ouput)
    {
        sequential_.push_back(ouput);
        return this;
    }

    NNBuilder *set_hidden_layer(std::vector<size_t> hidden);

private:
    std::vector<size_t>
        sequential_;
};

#endif // NEURAL_NETWORk_H
