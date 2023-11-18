#include <iostream>

int main() {
  char c{'a'};
  std::cout << c << ' ' << static_cast<int>(c) << '\n'; // prints a 97
  return 0;
}

// provides a compile time type check, making it harder to make an inadvertent error
