#include "matrix.h"
#include <cassert>

void testMatrix()
{
    // Test construction
    Matrix m1(2, 2);
    assert(m1.rows() == 2);
    assert(m1.cols() == 2);

    Matrix m2({{1.0, 2.0}, {3.0, 4.0}});
    assert(m2.rows() == 2);
    assert(m2.cols() == 2);

    // Test element access
    assert(m2(0, 0) == 1.0);
    assert(m2(1, 1) == 4.0);

    // Test addition
    Matrix m3 = m1 + m2;
    assert(m3(0, 0) == 1.0);
    assert(m3(1, 1) == 4.0);

    // Test subtraction
    Matrix m4 = m3 - m2;
    assert(m4(0, 0) == 0.0);
    assert(m4(1, 1) == 0.0);

    // Test multiplication
    Matrix m5 = m2 * m4;
    assert(m5(0, 0) == 0.0);
    assert(m5(1, 1) == 0.0);

    // Test scalar multiplication
    Matrix m6 = m2 * 2.0;
    assert(m6(0, 0) == 2.0);
    assert(m6(1, 1) == 8.0);

    // Test transpose
    Matrix m7 = m2.transpose();
    assert(m7(0, 0) == 1.0);
    assert(m7(1, 0) == 2.0);

    // Test matrix multiplication
    Matrix m8({{1.0, 2.0}, {3.0, 4.0}});
    Matrix m9({{5.0, 6.0}, {7.0, 8.0}});
    Matrix m10 = m8 * m9;
    assert(m10(0, 0) == 19.0);
    assert(m10(0, 1) == 22.0);
    assert(m10(1, 0) == 43.0);
    assert(m10(1, 1) == 50.0);
}

int main()
{
    testMatrix();
    return 0;
}