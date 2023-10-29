#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
    public:
        int goodPairs(std::vector<int> nums)
        {
            int res = 0;
            std::unordered_map<int, int> ans;

            for (int x : nums) {
                res += ans[x]++;
            }

            return res;
        }
};

int main()
{
    Solution sol;
    std::vector test = {1,2,3,1,1,3};
    
    int result = sol.goodPairs(test);

    std::cout << result << '\n';

    return 0;
};
