#include "loss.h"

#include <cmath>


double mse(const Vector & y_true, const Vector & y_pred)
{
    double sum = 0;
    for (size_t i = 0; i < y_true.size(); i++)
    {
        sum += std::pow(y_true[i] - y_pred[i], 2);
    }
    return sum / static_cast<double>(y_true.size());
}

double mae(const Vector &y_true, const Vector &y_pred)
{
    double sum = 0;
    for (size_t i = 0; i < y_true.size(); i++)
    {
        sum += std::abs(y_true[i] - y_pred[i]);
    }
    return sum / static_cast<double>(y_true.size());
}

double cross_entropy(const Vector &y_true, const Vector &y_pred)
{
    double sum = 0;
    for (size_t i = 0; i < y_true.size(); i++)
    {
        sum += y_true[i] * std::log(y_pred[i]);
    }
    return -sum / static_cast<double>(y_true.size());
}

double log_loss(const Vector &y_true, const Vector &y_pred) {
    // Ensure the vectors are of the same size
    if (y_true.size() != y_pred.size()) {
        throw std::invalid_argument("Vectors y_true and y_pred must be of the same size");
    }

    double loss = 0.0;
    const size_t n = y_true.size();

    for (size_t i = 0; i < n; ++i) {
        const double y = y_true[i];
        double p = y_pred[i];

        // To prevent taking the log of zero, which is undefined,
        // we can clip the values of p to a small range [epsilon, 1-epsilon]
        constexpr double epsilon = 1e-15;
        p = std::max(epsilon, std::min(1.0 - epsilon, p));

        loss += y * std::log(p) + (1 - y) * std::log(1 - p);
    }

    return -loss / n;
}

// initialize the static variables
LossFunction* Loss::MSE = new MSE_();
LossFunction* Loss::MAE = new MAE_();
LossFunction* Loss::CROSS_ENTROPY = new CrossEntropy_();
LossFunction* Loss::LOG_LOSS = new LogLoss_();