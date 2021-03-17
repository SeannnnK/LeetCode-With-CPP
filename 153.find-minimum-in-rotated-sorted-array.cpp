/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
// microsoft
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] <= nums[r]) {
                // rotate is not more half
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
    vector<int> nums{3, 4, 5, 1, 2};
    Solution sol;
    cout << sol.findMin(nums) << endl;
    return 0;
}
// @lc code=end
