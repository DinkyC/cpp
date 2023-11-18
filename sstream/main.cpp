#include <fstream>
#include <iostream>
#include <random>
#include <stdio.h>
#include <string>
#include <system_error>
#include <sstream>
#include <vector>

void knuth(std::ifstream &in) {
  std::string line;
  while (getline(in, line)) {
    std::istringstream iss(line);
    std::string word;
      while (iss >> word) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<std::string::size_type> dist(0, word.size()-1);
        std::string::size_type random_index = dist(gen);
        
        std::cout << word[random_index] << '\n';
    }
  }
}

int main(int, char **argv) {
  std::ifstream ifile(argv[1]);
  try {
    knuth(ifile);
  } catch (const std::invalid_argument &e) {
    std::cout << e.what() << '\n';
  }

  return 0;
}
