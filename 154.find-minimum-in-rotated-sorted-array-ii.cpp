/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l + 1 < r) {
            while (l < r && nums[l] == nums[l + 1]) {
                ++l;
            }
            while (l < r && nums[r] == nums[r - 1]) {
                --r;
            }
            mid = l + (r - l) / 2;
            if (nums[mid] <= nums[r]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (nums[l] > nums[r]) {
            return nums[r];
        }
        return nums[l];
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 3, 5};
    cout << sol.findMin(nums) << endl;
    return 0;
}
// @lc code=end