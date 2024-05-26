#include <iostream>
#include <cassert>

#include "vector.h"


void test_vector_addition() {
    Vector v1({1.0, 2.0, 3.0});
    Vector v2({4.0, 5.0, 6.0});
    Vector v3 = v1 + v2;
    assert(v3[0] == 5.0);
    assert(v3[1] == 7.0);
    assert(v3[2] == 9.0);
}

void test_vector_subtraction() {
    Vector v1({1.0, 2.0, 3.0});
    Vector v2({4.0, 5.0, 6.0});
    Vector v3 = v1 - v2;
    assert(v3[0] == -3.0);
    assert(v3[1] == -3.0);
    assert(v3[2] == -3.0);
}

void test_vector_dot() {
    Vector v1({1.0, 2.0, 3.0});
    Vector v2({4.0, 5.0, 6.0});
    double dot_product = v1.dot(v2);
    assert(dot_product == 32.0);

}

int main() {
    test_vector_addition();
    test_vector_subtraction();
    test_vector_dot();
    // More tests
    return 0;
}