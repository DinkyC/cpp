#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int goodPairsBrute(std::vector<int> nums) {
    int count = 0;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
      for (int j = i + 1; j < static_cast<int>(nums.size()); j++) {
        if (nums[i] == nums[j]) {
          count++;
        }
      }
    }
    return count;
  }

  int goodPairs(std::vector<int> nums) {
    std::unordered_map<int, int> cnt;
    int ans = 0;
    for (int x : nums) {
      ans += cnt[x]++;
    }

    return ans;
  }
};

int main() {
  std::vector<int> test = {1, 2, 3, 1, 1, 3};

  Solution sol;

  int result = sol.goodPairs(test);

  std::cout << result;
}
