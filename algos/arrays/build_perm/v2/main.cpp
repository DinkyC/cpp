#include <iostream>
#include <vector>

std::vector<int> buildArray(std::vector<int> &nums) {
  int n = static_cast<int>(nums.size());

  for (int i = 0; i < n; i++) {
    nums[i] = nums[i] + n * (nums[nums[i]] % n);
  }

  for (int i = 0; i < n; i++) {
    nums[i] /= n;
  }

  return nums;
}

int main() {
  std::vector<int> test = {1, 2, 3, 5, 6, 7};

  std::vector<int> new_test = buildArray(test);

  for (auto i : new_test) {
    std::cout << i << " ";
  }
}
