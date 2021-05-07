/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
// facebook

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int i = 0, n = nums.size(), res = n + 1;
        for (int j = 0; j < n; ++j) {
            target -= nums[j];
            while (target <= 0) {
                res = min(res, j - i + 1);
                target += nums[i++];
            }
        }

        return res % (n + 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums{2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, nums) << endl;
    return 0;
}
// @lc code=end
