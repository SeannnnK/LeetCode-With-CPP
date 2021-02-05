/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
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
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] > nums[l]) {
                if (nums[l] <= target && target <= nums[mid]) {
                    r = mid;
                } else {
                    l = mid;
                }
            } else if (nums[r] > nums[mid]) {
                if (nums[r] >= target && target >= nums[mid]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
        }

        if (nums[l] == target || nums[r] == target) {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << sol.search(nums, target) << endl;
    return 0;
}
// @lc code=end