# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MathLibrary VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
set(SOURCES
    src/vector.cpp
    src/matrix.cpp
    src/activation.cpp
    src/layer.cpp
)

# Add the main library
add_library(mathlib ${SOURCES})

# Add the executable for tests
add_executable(test_vector tests/vector_test.cpp)
add_executable(test_matrix tests/matrix_test.cpp)
add_executable(test_activation tests/activation_test.cpp)
add_executable(test_layer tests/layer_test.cpp)

# Link the library to the executable
target_link_libraries(test_vector mathlib)
target_link_libraries(test_matrix mathlib)
target_link_libraries(test_activation mathlib)
target_link_libraries(test_layer mathlib)

# Enable testing
enable_testing()

# Add a test
add_test(NAME TestVector COMMAND test_vector)
add_test(NAME TestMatrix COMMAND test_matrix)
add_test(NAME TestActivation COMMAND test_activation)
add_test(NAME TestLayer COMMAND test_layer)
