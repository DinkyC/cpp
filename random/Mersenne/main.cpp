#include <iostream>
#include <random> // for std::mt19937

class Random {
public:
  void fullRange() {
    std::mt19937 mt{};

    for (int count{0}; count <= 40; ++count) {
      std::cout << mt() << '\n';

      if (count % 5 == 0) {
        std::cout << '\n';
      }
    }
  }

  void range() {
    std::mt19937 mt{};
    
    // Create a reusable random number generator that generates
    // uniform numbers between 1 and 6
    std::uniform_int_distribution<> die6{1, 6};
    
    // print a bunch of random numbers
    for (int count{1}; count <= 40; ++count) {
      std::cout << die6(mt) << '\t';

      if (count % 10 == 0) {
        std::cout << '\n';
      }
    }
  }
};

int main() { 
    Random rand;

    rand.fullRange();

    rand.range();

    return 0; 
}
