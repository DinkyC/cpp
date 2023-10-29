#include <cstdlib>
#include <iostream>

void cleanup() { std::cout << "cleanup!\n"; }

int main() {
  std::cout << 1 << '\n';
  cleanup();

  std::exit(0); // terminate and return status code 0 to operating system

  // The following statements never execute
  std::cout << 2 << '\n';

  return 0;
}
