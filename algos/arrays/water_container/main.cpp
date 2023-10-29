#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> heights) {
    int res = 0, l = 0, r = static_cast<int>(heights.size());
    while (l < r) {
      int area = (r - l) * std::min(heights[l], heights[r]);
      res = std::max(res, area);
      if (heights[l] < heights[r])
        l += 1;
      else
        r -= 1;
    }
    return res;
  }
};

int main() {
  Solution sol;

  std::vector<int> test = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  int solution = sol.maxArea(test);

  std::cout << "The max area is: " << solution << '\n';
  return 0;
}
