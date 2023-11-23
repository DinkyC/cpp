# Compiler flags
CXXFLAGS += -I/opt/homebrew/Cellar/boost/1.83.0/include -g -Wall -Wextra -Werror -Wshadow -pedantic -Wconversion -Wfloat-equal -Wsign-compare -std=c++20 -O0
LDFLAGS += -L/opt/homebrew/Cellar/boost/1.83.0/lib -lboost_system # Replace with the actual Boost libraries you need

# Compilation command
main: main.cpp
	g++ $(CXXFLAGS) main.cpp -o main $(LDFLAGS)

