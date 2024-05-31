# minimum version of cmake required
cmake_minimum_required(VERSION 3.28)

# project name
project(numpy_clone VERSION 1.0)

# set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# add include library
include_directories(${PROJECT_SOURCE_DIR}/include)

# add source files
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# add the main library
add_library(np SHARED ${SOURCES}
        tests/main.cpp
        include/array.h
        include/utils.h)

# add executable for the tests
add_executable(tests ${PROJECT_SOURCE_DIR}/tests/main.cpp)

# link the library to the executable
target_link_libraries(tests np)

# enable testing
enable_testing()

# add the test
add_test(NAME test COMMAND tests)
