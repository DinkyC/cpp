#include <iostream>
#include <string>
class Solution {
public:
  // Time Complexity: O(n); Space Complexity O(n)
  std::string mergeString(std::string word_1, std::string word_2) {

    std::string res;
    int len_1 = static_cast<int>(word_1.length());
    int len_2 = static_cast<int>(word_2.length());

    int i = 0;

    while (i < len_1 || i < len_2) {
      if (i < len_1) {
        res.push_back(word_1[i]);
      }
      if (i < len_2) {
        res.push_back(word_2[i]);
      }

      i++;
    }
    return res;
  }
};

int main() {
  Solution sol;

  std::string word_1 = "hello";
  std::string word_2 = "yoyo";

  std::string result = sol.mergeString(word_1, word_2);

  std::cout << result << '\n';

  return 0;
}
