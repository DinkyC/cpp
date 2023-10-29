# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -ggdb

# Target executable
TARGET = io

# Source files
SRCS = io.cpp

# Default target
all: $(TARGET)

# Rule for building the target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean rule
clean:
	rm -f $(TARGET)

