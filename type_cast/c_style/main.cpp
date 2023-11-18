#include <iostream>

int main() {
  int x{10};
  int y{4};

  double d{(double)x /
           y}; // convert x to a double so we get floating point division / Also works with double(x)
  std::cout << d << '\n'; // prints 2.5

  return 0;
}
