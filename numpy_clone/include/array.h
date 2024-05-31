//
// Created by Daniel Attali on 29/05/2024.
//

#ifndef ARRAY_H
#define ARRAY_H

#include "utils.h"

#include <array>
#include <vector>

// this is a multidimensional array class that can be used to store any type of data, vector, matrix, cube, etc.
// it is a template class that can be used with any type of data, and it is implemented using a single array

namespace np {
    template <typename T>
    class Array {
    public:
        // Constructor
        Array(const std::initializer_list<size_t> shape) : shape_(shape) {
            // init an array with of the shape given
            size_t size = np::prod(shape);
            data_ = std::array<T, size>();
        }

        Array(const std::initializer_list<size_t> shape, T val) : shape_(shape) {
            // init an array with of the shape given
            size_t size = np::prod(shape);
            data_ = std::array<T, size>();

            for (size_t i = 0; i < size; ++i) {
                data_[i] = val;
            }
        }

        Array(const std::initializer_list<size_t> shape, const std::array<T>& data) : shape_(shape), data_(data) {
            // check if the data size is equal to the product of the shape
            if (data.size() != np::prod(shape)) {
                throw std::invalid_argument("Data size is not equal to the product of the shape");
            }
        }

        // getters
        [[nodiscard]] size_t size() const {
            return data_.size();
        }

        [[nodiscard]] std::vector<size_t> shape() const {
            return shape_;
        }

        // flatten the array
        np::Array<T> flatten() {
            return np::Array<T>({size()}, data_);
        }

        // implement the operator[] to access the data it will receives a vector of indexes
        T& operator[](const std::vector<size_t>& indexes) {
            // check if the indexes size is equal to the shape size
            if (indexes.size() != shape_.size()) {
                throw std::invalid_argument("Indexes size is not equal to the shape size");
            }

            // calculate the index
            size_t index = 0;
            for (size_t i = 0; i < indexes.size(); ++i) {
                index += indexes[i] * np::prod(std::vector<size_t>(shape_.begin() + i + 1, shape_.end()));
            }

            return data_[index];
        }

        T& operator[](const size_t index) {
            return data_[index];
        }

        // accessing sub arrays
        // for example if we have a 3D {2, 3, 4} array
        // if we access the first index we will get a 2D {3, 4} array
        // if we access the second index we will get a 2D {4} array
        // if we access the third index we will get a 1D array
        np::Array<T> operator[](const size_t index) {
            // check if the index is less than the shape size
            if (index >= shape_.size()) {
                throw std::invalid_argument("Index is greater than the shape size");
            }

            // calculate the new shape
            std::vector<size_t> new_shape(shape_.begin() + index + 1, shape_.end());

            // calculate the new data
            size_t size = np::prod(new_shape);
            std::array<T> new_data{};
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data_[i];
            }

            return np::Array<T>(new_shape, new_data);
        }

        // implement the iterator pattern to access the data
        struct  Iterator {
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = T;
            using pointer           = T*;  // or also value_type*
            using reference         = T&;  // or also value_type&

            Iterator(const pointer ptr) : m_ptr(ptr) {}

            reference operator*() const { return *m_ptr; }
            pointer operator->() { return m_ptr; }

            Iterator operator++() {
                ++m_ptr;
                return *this;
            }

            Iterator operator++(int) {
                Iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
        private:
            pointer m_ptr;
        };

        Iterator begin() { return Iterator(data_.data()); }
        Iterator end() { return Iterator(data_.data() + data_.size()); }


    private:
        std::vector<size_t> shape_;
        std::array<T> data_{};
    };
}

#endif //ARRAY_H
