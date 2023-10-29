#include <iostream>
#include <random>
#include <set>
#include <stdexcept>

class RandomNumber {
public:
  void generate(int offset, int range, int num = 5) {
    if (num > range)
      throw std::runtime_error(
          "Cannot generate more unique numbers than the specified range.");

    std::set<int> uniqueNumbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(offset, offset + range - 1);

    while (uniqueNumbers.size() < static_cast<size_t>(num)) {
      uniqueNumbers.insert(distrib(gen));
    }

    for (int n : uniqueNumbers) {
      std::cout << n << '\n';
    }
  }
};

int main(int argc, char *argv[]) {
  if (argc < 4) {
    std::cerr << "Usage: program_name offset range num" << std::endl;
    return 1;
  }

  RandomNumber randGen;

  int offset = std::stoi(argv[1]);
  int range = std::stoi(argv[2]);
  int num = std::stoi(argv[3]);

  try {
    randGen.generate(offset, range, num);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
