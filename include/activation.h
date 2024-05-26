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
    virtual double operator()(double x) const = 0;
    virtual double derivative(double x) const = 0;
};

class ReLU : public Activation {
public:
    double operator()(double x) const override {
        return relu(x);
    }
    double derivative(double x) const override {
        return relu_derivative(x);
    }

};

class Sigmoid : public Activation {
public:
    double operator()(double x) const override {
        return sigmoid(x);
    }
    double derivative(double x) const override {
        return sigmoid_derivative(x);
    }
};

class Tanh : public Activation {
public:
    double operator()(double x) const override {
        return tanh_(x);
    }
    double derivative(double x) const override {
        return tanh_derivative(x);
    }
};

#endif // ACTIVATION_H
