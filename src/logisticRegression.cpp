#include <cmath>
#include <vector>

#include "vector.h"
#include "logisticRegression.h"

LogisticRegression::LogisticRegression() : x_(), y_(), theta_() {}

LogisticRegression::LogisticRegression(const std::vector<Vector> &x, const std::vector<Vector> &y)
{
    x_ = x;
    y_ = y;
}

void LogisticRegression::fit() {
    // Initialize theta and beta
    theta_ = Vector(x_[0].size());
    beta_ = 0;

    for (uint16_t epoch = 0; epoch < epochs_; ++epoch) {
        // Calculate the gradient
        Vector gradient = Vector(x_[0].size());
        double beta_gradient = 0;

        for (uint16_t i = 0; i < x_.size(); ++i) {
            double prediction = predict(x_[i]);
            double error = y_[i][0] - prediction;

            gradient = gradient + (x_[i]  * error);
            beta_gradient += error;
        }

        // Update theta and beta
        theta_ += gradient * learning_rate_ ;
        beta_ += beta_gradient * learning_rate_;
    }
}

double LogisticRegression::predict(const Vector &x) const {
    return 1 / (1 + exp(-(theta_.dot(x) + beta_)));
}

double LogisticRegression::accuracy(const std::vector<Vector> &x, const std::vector<Vector> &y) const {
    double correct = 0;

    for (uint16_t i = 0; i < x.size(); ++i) {
        double prediction = predict(x[i]);
        if (prediction >= 0.5 && y[i][0] == 1) {
            ++correct;
        } else if (prediction < 0.5 && y[i][0] == 0) {
            ++correct;
        }
    }

    return static_cast<double>(correct) / x.size();
}