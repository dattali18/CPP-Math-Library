#include <iostream>
#include <vector>

#include "vector.h"
#include "logisticRegression.h"

void test_logistic() {
    std::vector<Vector> x = {Vector({1, 2}), Vector({2, 3}), Vector({3, 4}), Vector({4, 5})};
    std::vector<Vector> y = {Vector({0}), Vector({0}), Vector({1}), Vector({1})};

    LogisticRegression lr(x, y);
    lr.fit();

    std::cout << "Accuracy: " << lr.accuracy(x, y) << std::endl;
}

int main() {
    test_logistic();
    return 0;
}