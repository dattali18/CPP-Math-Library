//
// Created by Daniel Attali on 29/05/2024.
//

#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <initializer_list>

#include "array.h"

namespace np {
    template <typename T>
    T sum(np::Array<T> list) {
        double sum = 0;
        for (auto it = list.begin(); it != list.end(); ++it) {
            sum += *it;
        }
        return sum;
    }

    template<typename T>
    T prod(np::Array<T> list) {
        double prod = 1;
        for (auto it = list.begin(); it != list.end(); ++it) {
            prod *= *it;
        }
        return prod;
    }

    template<typename T>
    T prod(std::initializer_list<T> list) {
        double prod = 1;
        for (auto it = list.begin(); it != list.end(); ++it) {
            prod *= *it;
        }
        return prod;
    }

    template <typename T>
    T mean(np::Array<T> list) {
        return sum(list) / list.size();
    }

    template <typename T>
    T std(np::Array<T> list) {
        double mean = np::mean(list);
        double sum = 0;
        for (auto it = list.begin(); it != list.end(); ++it) {
            sum += (*it - mean) * (*it - mean);
        }
        return sqrt(sum / list.size());
    }

    template <typename T>
    double var(np::Array<T> list) {
        return std(list) * std(list);
    }

    template <typename T>
    T min(np::Array<T> list) {
        double min = *list.begin();
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (*it < min) {
                min = *it;
            }
        }
        return min;
    }

    template <typename T>
    T max(np::Array<T> list) {
        double max = *list.begin();
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (*it > max) {
                max = *it;
            }
        }
        return max;
    }

    // dot product of two array
    template <typename T>
    np::Array<T> dot(const np::Array<T>& a, const np::Array<T>& b) {
        // check if the shapes are compatible
        if (a.shape().size() != 2 || b.shape().size() != 2 || a.shape()[1] != b.shape()[0]) {
            throw std::invalid_argument("Shapes are not compatible for dot product");
        }

        // create a new array with the shape of the dot product
        np::Array<T> c({a.shape()[0], b.shape()[1]});

        // calculate the dot product
        for (size_t i = 0; i < a.shape()[0]; ++i) {
            for (size_t j = 0; j < b.shape()[1]; ++j) {
                T sum = 0;
                for (size_t k = 0; k < a.shape()[1]; ++k) {
                    sum += a.data_[i * a.shape()[1] + k] * b.data_[k * b.shape()[1] + j];
                }
                c.data_[i * c.shape()[1] + j] = sum;
            }
        }

        return c;
    }
}

#endif //UTILS_H
