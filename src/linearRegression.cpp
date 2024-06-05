#include "linearRegression.h"

#include "vector.h"

LinearRegression::LinearRegression() : x_(), y_(), theta_() {}

LinearRegression::LinearRegression(const std::vector<Vector> &x, const std::vector<Vector> &y)
    : x_(x), y_(y) {}

void LinearRegression::fit()
{
    // this function will fit the model to the data using the gradient descent algorithm
    // we will use the following formulas:
    // theta = theta - alpha * dJ/dtheta

    // we will initialize theta to 0
    theta_ = Vector(x_[0].size(), 0);
    beta_ = 0;

    // we will iterate over the data and update theta and beta
    for (uint16_t epoch = 0; epoch < epochs_; ++epoch)
    {
        Vector dJ_dtheta(x_[0].size(), 0);
        double dJ_dbeta = 0;

        for (size_t i = 0; i < x_.size(); ++i)
        {
            double error = predict(x_[i]) - y_[i][0];
            dJ_dtheta = dJ_dtheta + x_[i] * error;
            dJ_dbeta += error;
        }

        theta_ = theta_ - dJ_dtheta * learning_rate_;
        beta_ = beta_ - dJ_dbeta * learning_rate_;
    }
}

double LinearRegression::predict(const Vector &x) const
{
    // this function will predict the value of y given x
    return theta_.dot(x) + beta_;
}
