#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
void knuth(std::vector<std::string> x) {
  int length = static_cast<int>(x.size());

  // seed the random number generater with time
  std::srand(time(NULL));
  // generate a random number
  int r = rand() % length;

  // swap randomly selected element to the back of the vector
  std::swap(x[r], x.back());

  // print the results
  std::cout << x.back();
}

int main() {
  std::vector<std::string> test = {"hello", "friend"};
  knuth(test);
  return 0;
}
