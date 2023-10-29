#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> buildArray(std::vector<int>& nums) {
        std::vector<int> temp;
        for (int i=0; i < static_cast<int>(nums.size()); i++){
            temp.push_back(nums[nums[i]]);
        }
        return temp;
    }
};


int main()
{
    Solution sol;
    std::vector<int> arr = {0,2,1,5,3,4};
    std::vector<int> new_arr = sol.buildArray(arr);

    for (auto i : new_arr) {
        std::cout << i << " ";
    }
    return 0;
}
