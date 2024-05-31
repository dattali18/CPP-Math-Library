//
// Created by Daniel Attali on 29/05/2024.
//

#include <iostream>

#include "array.h"
#include "utils.h"

void test_array() {
    np::Array<int> a({2, 3, 4}, 0);

    std::cout << a.size() << std::endl;
    std::cout << a.shape().size() << std::endl;
    std::cout << a.flatten().size() << std::endl;
}

int main() {
    test_array();
    return 0;
}