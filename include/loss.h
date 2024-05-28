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

// a class that will be use to store the different loss functions

class LossFunction 
{
public:
    virtual ~LossFunction() = default;

    [[nodiscard]] virtual double call(const Vector &y_true, const Vector &y_pred) const = 0;
};

class MSE_ final : public LossFunction
{
public:
    [[nodiscard]] double call(const Vector &y_true, const Vector &y_pred) const override
    {
        return mse(y_true, y_pred);
    }
};

class MAE_ final : public LossFunction
{
public:
    [[nodiscard]] double call(const Vector &y_true, const Vector &y_pred) const override
    {
        return mae(y_true, y_pred);
    }
};


class CrossEntropy_ final : public LossFunction
{

public:
    [[nodiscard]] double call(const Vector &y_true, const Vector &y_pred) const override
    {
        return cross_entropy(y_true, y_pred);
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
};

#endif