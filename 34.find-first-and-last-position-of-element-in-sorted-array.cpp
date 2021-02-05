/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) {
            return res;
        }
        res[0] = lower_bound_index(nums, target);
        if (res[0] == -1) {
            return res;
        }
        res[1] = upper_bound_index(nums, target);
        return res;
    }

private:
    int lower_bound_index(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int l = 0, r = nums.size() - 1;
        int mid = 0;
         while (l + 1 < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (nums[l] == target) {
            return l;
        } else if (nums[r] == target) {
            return r;
        } else {
            return -1;
        }
    }
    
    int upper_bound_index(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (nums[r] == target) {
            return r;
        } else if (nums[l] == target) {
            return l;
        } else {
            return -1;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> res = sol.searchRange(nums, target);
    cout << res[0] << " " << res[1];
    cout << endl;
    return 0;
}
// @lc code=end