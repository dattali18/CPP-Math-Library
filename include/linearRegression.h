// linearRegression.h
// Purpose: Header file for the LinearRegression class.
// Written by: Daniel Attali

#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <vector>
#include "vector.h"

class LinearRegression
{
public:
    LinearRegression();
    LinearRegression(const std::vector<Vector> &x, const std::vector<Vector> &y);

    void setX(const std::vector<Vector> &x) { x_ = x; }
    void setY(const std::vector<Vector> &y) { y_ = y; }
    void setLearningRate(double learning_rate) { learning_rate_ = learning_rate; }
    void setEpochs(uint16_t epochs) { epochs_ = epochs; }

    // Linear regression: y = theta1 * x1 + theta2 * x2 + ... + beta

    // Fit the model
    void fit();

    double predict(const Vector &x) const;

private:
    std::vector<Vector> x_;
    std::vector<Vector> y_;

    Vector theta_;
    double beta_;

    double learning_rate_ = 0.01;
    uint16_t epochs_ = 1000;
};

#endif // LINEARREGRESSION_H