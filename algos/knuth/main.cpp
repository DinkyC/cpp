#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
template<typename T>
void knuth(std::vector<T> x) {
  int length = static_cast<int>(x.size());
  for (int i = 0; i < (length-1); i++) {
      // generate a random number
      int r = rand() % length;
      
      // swap randomly selected element to the back of the vector
      std::swap(x[static_cast<std::vector<std::string>::size_type>(r)], x.back());
  }

  // print the results
  std::cout << x.back();
}

int main() {
  std::vector<std::string> test = {"hello", "friend", "yo", "fuck"};
  // seed the random number generater with time
  std::srand((unsigned)time(NULL));

  knuth<std::string>(test);
  return 0;
}
