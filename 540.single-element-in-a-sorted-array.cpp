/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (mid % 2) {
                mid = mid - 1;
            }
            if (nums[mid] != nums[mid + 1]) {
                r = mid;
            } else {
                l = mid + 2;
            }
        }
        return nums[l];
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << sol.singleNonDuplicate(nums) << endl;
    return 0;
}
// @lc code=end