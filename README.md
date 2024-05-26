# Math Library

In this project we will be building a math library in `cpp`
This library will be used in building simple Neural Network library in the future.

## Structure

The library will be divided into the following parts:

1. Vector
2. Matrix
3. Activation Functions
4. Layers

## UML

```mermaid
classDiagram
    class Vector {
        +Vector(size_t size)
        +Vector(const std::vector~double~& data)
        +Vector(const Vector& other)

        -std::vector~double~ data_
    }

    class Matrix {
        +Matrix(size_t rows, size_t cols)
        +Matrix(const std::vector~std::vector~double~~& data)
        +Matrix(const Vector& vec)
        +Matrix mult(const Matrix& other) const
        +Matrix transpose() const
        -std::vector~std::vector~double~~ data_
    }

    class Activation {
        <<abstract>>
        +double call(double x) const
        +double derivative(double x) const
    }

    class ReLU_ {
        +double call(double x) const
        +double derivative(double x) const
    }

    class Sigmoid_ {
        +double call(double x) const
        +double derivative(double x) const
    }

    class Tanh_ {
        +double call(double x) const
        +double derivative(double x) const
    }

    class Functions {
        +static Activation* ReLU
        +static Activation* Sigmoid
        +static Activation* Tanh
    }

    class Layer {
        +Layer(size_t input_size, size_t output_size)
        +Vector forward(const Vector& input)
        +void backward(const Vector& grad, double learning_rate)
        -Matrix weights_
        -Vector biases_
        -Vector last_input_
        -Vector last_output_
        -Activation* activation_
    }

    Vector --> Matrix
    Matrix --> Vector
    Layer --> Matrix
    Layer --> Vector
    Layer --> Activation
    Activation <|-- ReLU_
    Activation <|-- Sigmoid_
    Activation <|-- Tanh_
    Functions --> Activation

```

