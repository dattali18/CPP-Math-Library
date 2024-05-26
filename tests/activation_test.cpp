#include "activation.h"

#include <cassert>
#include <cmath>
#include <iostream>

void test_relu() {
    assert(relu(1.0) == 1.0);
    assert(relu(-1.0) == 0.0);
}

void test_sigmoid(double epsilon = 1e-5) {
    assert(std::abs(sigmoid(0.0) - 0.5) < epsilon);
    assert(std::abs(sigmoid(1.0) - 0.73105857) < epsilon);
}

void test_tanh() {
    assert(std::abs(tanh_(0.0) - 0.0) < 1e-5);
    assert(std::abs(tanh_(1.0) - 0.761594) < 1e-5);
}

int main() {
    test_relu();
    test_sigmoid();
    test_tanh();
    return 0;
}
