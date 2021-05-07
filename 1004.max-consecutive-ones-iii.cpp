/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
// unknown
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the
// array if you can flip at most k 0's.
// Translation: Find the longest subarray with at most K zeros.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int i = 0, res = 0, n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (nums[j] == 0) {
                --k;
            }
            while (k < 0) {
                if (nums[i++] == 0) {
                    ++k;
                }
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << sol.longestOnes(nums, 2) << endl;
    return 0;
}
// @lc code=end
