/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
// bloomberg

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        if (nums.size() < 3) {
            return 0;
        }
        int res = nums[0] + nums[1] + nums.back();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int low = i + 1, high = nums.size() - 1, sum;
            while (low < high) {
                sum = nums[i] + nums[low] + nums[high];
                if (sum > target) {
                    --high;
                } else if (sum < target) {
                    ++low;
                } else {
                    return sum;
                }
                res = abs(sum - target) < abs(res - target) ? sum : res;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<pair<vector<int>, int>> inputs{{{-1, 2, 1, -4}, 1}};
    for (auto& input : inputs) {
        cout << sol.threeSumClosest(input.first, input.second) << endl;
    }
    return 0;
}
// @lc code=end
