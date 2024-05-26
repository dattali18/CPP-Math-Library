# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MathLibrary VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
set(SOURCES
    src/vector.cpp
)

# Add the main library
add_library(mathlib ${SOURCES})

# Add the executable for tests
add_executable(test_vector tests/vector_test.cpp)

# Link the library to the executable
target_link_libraries(test_vector mathlib)

# Enable testing
enable_testing()

# Add a test
add_test(NAME TestVector COMMAND test_vector)