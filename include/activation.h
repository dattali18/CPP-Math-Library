#ifndef ACTIVATION_H
#define ACTIVATION_H

double relu(double x);
double relu_derivative(double x);

double sigmoid(double x);
double sigmoid_derivative(double x);

double tanh_(double x);
double tanh_derivative(double x);


class Activation {
public:
    virtual double call(double x) const = 0;
    virtual double derivative(double x) const = 0;

};

class ReLU_ : public Activation {
public:
    double call(double x) const override {
        return relu(x);
    }
    double derivative(double x) const override {
        return relu_derivative(x);
    }

};

class Sigmoid_ : public Activation {
public:
    double call(double x) const override {
        return sigmoid(x);
    }
    double derivative(double x) const override {
        return sigmoid_derivative(x);
    }
};

class Tanh_ : public Activation {
public:
    double call(double x) const override {
        return tanh_(x);
    }
    double derivative(double x) const override {
        return tanh_derivative(x);
    }
};

class Functions {
    public:
    static Activation* ReLU;
    static Activation* Sigmoid;
    static Activation* Tanh;
};


#endif // ACTIVATION_H
