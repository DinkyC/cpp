# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -ggdb

# Target executable
TARGET = test

# Source files
SRCS = test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule for building the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for building object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

