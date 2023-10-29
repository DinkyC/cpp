/* Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 *
 * Example -> 
 *  Input: nums = [2,7,11,15], target = 9
 *  Output: [0,1]
 *  Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 */

#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map <int, int> numMap;
        int n = static_cast<int>(nums.size());

        // find the compliment
        for (int i=0; i<n; i++){
            int compliment = target - nums[i];

            // build hashmap
            numMap[nums[i]] = i;

            if (numMap.count(compliment)){
                return {numMap[compliment], i};
            }
        }

        return {};  
    }
};



int main()
{
    Solution sol;

    std::vector<int> test = {2,7,11,15};
    int target = 9;

    std::vector<int> x{ sol.twoSum(test, target) };

    for (int i : x){
        std::cout << i << " ";
    }

    return 0;
}
