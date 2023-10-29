#include <cstdlib>
#include <iostream>

// code here to do any kind of cleanup required
void cleanup() { std::cout << "cleanup!\n"; }

int main() {
  // register cleanup() to be called automatically when std::exit() is called
  std::atexit(cleanup);

  std::cout << 1
            << '\n'; // note: we use cleanup rather than cleanup() since we're
                     // not making a function call to cleanup() right now

  std::exit(0); // terminate and return status code 0 to operating system

  // The following statements never execute
  std::cout << 2 << '\n';

  return 0;
}
