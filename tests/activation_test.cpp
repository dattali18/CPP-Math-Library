#include "activation.h"
#include <cassert>

void testRelu() {
    // Test positive input
    assert(relu(5.0) == 5.0);
    // Test negative input
    assert(relu(-3.0) == 0.0);
    // Test zero input
    assert(relu(0.0) == 0.0);
}

void testReluDerivative() {
    // Test positive input
    assert(relu_derivative(5.0) == 1.0);
    // Test negative input
    assert(relu_derivative(-3.0) == 0.0);
    // Test zero input
    assert(relu_derivative(0.0) == 0.0);
}

void testSigmoid() {
    // Test positive input
    assert(sigmoid(2.0) == 0.8807970779778823);
    // Test negative input
    assert(sigmoid(-1.0) == 0.2689414213699951);
    // Test zero input
    assert(sigmoid(0.0) == 0.5);
}

void testSigmoidDerivative() {
    // Test positive input
    assert(sigmoid_derivative(2.0) == 0.10499358540350662);
    // Test negative input
    assert(sigmoid_derivative(-1.0) == 0.19661193324148185);
    // Test zero input
    assert(sigmoid_derivative(0.0) == 0.25);
}

void testTanh() {
    // Test positive input
    assert(tanh_(1.0) == 0.7615941559557649);
    // Test negative input
    assert(tanh_(-0.5) == -0.46211715726000974);
    // Test zero input
    assert(tanh_(0.0) == 0.0);
}

void testTanhDerivative() {
    // Test positive input
    assert(tanh_derivative(1.0) == 0.41997434161402614);
    // Test negative input
    assert(tanh_derivative(-0.5) == 0.7864477329659275);
    // Test zero input
    assert(tanh_derivative(0.0) == 1.0);
}

int main() {
    testRelu();
    // testReluDerivative();
    // testSigmoid();
    // testSigmoidDerivative();
    // testTanh();
    // testTanhDerivative();

    return 0;
}