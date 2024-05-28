#include "loss.h"

#include <cmath>


double mse(const Vector & y_true, const Vector & y_pred)
{
    double sum = 0;
    for (size_t i = 0; i < y_true.size(); i++)
    {
        sum += std::pow(y_true[i] - y_pred[i], 2);
    }
    return sum / y_true.size();
}

double mae(const Vector &y_true, const Vector &y_pred)
{
    double sum = 0;
    for (size_t i = 0; i < y_true.size(); i++)
    {
        sum += std::abs(y_true[i] - y_pred[i]);
    }
    return sum / y_true.size();
}

double cross_entropy(const Vector &y_true, const Vector &y_pred)
{
    double sum = 0;
    for (size_t i = 0; i < y_true.size(); i++)
    {
        sum += y_true[i] * std::log(y_pred[i]);
    }
    return -sum / y_true.size();
}

// initialize the static variables
LossFunction* Loss::MSE = new MSE_();
LossFunction* Loss::MAE = new MAE_();
LossFunction* Loss::CROSS_ENTROPY = new CrossEntropy_();