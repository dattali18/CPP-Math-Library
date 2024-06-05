// this file is a test file for the LinearRegression class
//  where we will tests the fit and predict functions

#include "linearRegression.h"

#include <vector>
#include <iostream>

#include "vector.h"

void test_linear() {
    // we will create a dataset of 2D points
    std::vector<Vector> x = {Vector({1, 1}), Vector({2, 2}), Vector({3, 3}), Vector({4, 4}), Vector({5, 5})};
    std::vector<Vector> y = {Vector({2}), Vector({4}), Vector({6}), Vector({8}), Vector({10})};

    // we will create a LinearRegression object
    LinearRegression lr(x, y);

    // we will fit the model to the data
    lr.fit();

    // we will predict the value of y given x
    Vector x_test({6, 6});
    // what is the ouput? we expect 12
    std::cout << "The predicted value of y given x = [6, 6] is: " << lr.predict(x_test) << std::endl;
}

int main()
{
    test_linear();
    return 0;
}