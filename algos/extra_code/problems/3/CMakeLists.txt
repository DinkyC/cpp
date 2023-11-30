cmake_minimum_required(VERSION 3.16)
project(PercolationSimulation)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Werror -Wshadow -pedantic -Wconversion -Wfloat-equal -Wsign-compare -O0")

# Specify source files
set(SOURCES
    src/main.cpp
    src/percolate.cpp
    src/union.cpp
)

# Add the executable
add_executable(main ${SOURCES})

# Include directories
target_include_directories(main PRIVATE include)

