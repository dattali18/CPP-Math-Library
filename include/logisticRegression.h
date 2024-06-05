#ifndef LOGISTICREGRESSION_H
#define LOGISTICREGRESSION_H

#include "vector.h"

#include <vector>

class LogisticRegression
{
public:
    LogisticRegression();
    LogisticRegression(const std::vector<Vector> &x, const std::vector<Vector> &y);

    void setX(const std::vector<Vector> &x) { x_ = x; }
    void setY(const std::vector<Vector> &y) { y_ = y; }
    void setLearningRate(double learning_rate) { learning_rate_ = learning_rate; }
    void setEpochs(uint16_t epochs) { epochs_ = epochs; }

    // Logistic regression: y = 1 / (1 + exp(-(theta1 * x1 + theta2 * x2 + ... + beta)))
    void fit();

    double predict(const Vector &x) const;

    double accuracy(const std::vector<Vector> &x, const std::vector<Vector> &y) const;
private:
    std::vector<Vector> x_;
    std::vector<Vector> y_;

    Vector theta_;
    double beta_ = 0;

    double learning_rate_ = 0.01;
    uint16_t epochs_ = 1000;
};

#endif // LOGISTICREGRESSION_H