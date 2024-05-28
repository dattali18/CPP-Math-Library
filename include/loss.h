#ifndef LOSS_H
#define LOSS_H

// this file will contain the loss functions

#include "vector.h"

// mean squared error loss
double mse(const Vector &y_true, const Vector &y_pred);

// mean absolute error loss
double mae(const Vector &y_true, const Vector &y_pred);

// cross entropy loss
double cross_entropy(const Vector &y_true, const Vector &y_pred);

double log_loss(const Vector &y_true, const Vector &y_pred);

// a class that will be use to store the different loss functions

class LossFunction 
{
public:
    virtual ~LossFunction() = default;

    [[nodiscard]] virtual double loss(const Vector &y_true, const Vector &y_pred) const = 0;
    [[nodiscard]] virtual Vector gradient(const Vector &y_true, const Vector &y_pred) const = 0;
};

class MSE_ final : public LossFunction
{
public:
    [[nodiscard]] double loss(const Vector &y_true, const Vector &y_pred) const override
    {
        return mse(y_true, y_pred);
    }

    [[nodiscard]] Vector gradient(const Vector &y_true, const Vector &y_pred) const override {
        return (y_pred - y_true) * 2;
    }
};

class MAE_ final : public LossFunction
{
public:
    [[nodiscard]] double loss(const Vector &y_true, const Vector &y_pred) const override
    {
        return mae(y_true, y_pred);
    }

    [[nodiscard]] Vector gradient(const Vector &y_true, const Vector &y_pred) const override {
        return (y_pred - y_true) / (y_pred - y_true).abs();
    }
};


class CrossEntropy_ final : public LossFunction
{

public:
    [[nodiscard]] double loss(const Vector &y_true, const Vector &y_pred) const override
    {
        return cross_entropy(y_true, y_pred);
    }

    [[nodiscard]] Vector gradient(const Vector &y_true, const Vector &y_pred) const override {
        return y_pred - y_true;
    }
};

class LogLoss_ final : public LossFunction {
public:
    [[nodiscard]] double loss(const Vector &y_true, const Vector &y_pred) const override {
        return log_loss(y_true, y_pred);
    }

    [[nodiscard]] Vector gradient(const Vector &y_true, const Vector &y_pred) const override {
        // Ensure the vectors are of the same size
        if (y_true.size() != y_pred.size()) {
            throw std::invalid_argument("Vectors y_true and y_pred must be of the same size");
        }

        const size_t n = y_true.size();
        Vector grad(n);

        for (size_t i = 0; i < n; ++i) {
            const double y = y_true[i];
            double p = y_pred[i];

            // To prevent taking the log of zero, which is undefined,
            // we can clip the values of p to a small range [epsilon, 1-epsilon]
            constexpr double epsilon = 1e-15;
            p = std::max(epsilon, std::min(1.0 - epsilon, p));

            grad[i] = (p - y) / (p * (1 - p));
        }

        return grad;
    }
};

class Loss
{
public:
    Loss() = default;
    ~Loss() = default;
    
    static LossFunction* MSE;
    static LossFunction* MAE;
    static LossFunction* CROSS_ENTROPY;
    static LossFunction* LOG_LOSS;
};

#endif