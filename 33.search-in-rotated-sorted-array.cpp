/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
// bloomberg | facebook | linkedin | microsoft | uber
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        // unique in nums
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < nums[r]) {
                // rotate is not more than half, this is in order
                if (nums[mid] <= target && target <= nums[r]) {
                    l = mid;
                } else {
                    r = mid;
                }
            } else if (nums[l] < nums[mid]) {
                // rotate is more than hlaf, this interval is in order
                if (nums[l] <= target && target <= nums[mid]) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
        }
        if (nums[l] == target) {
            return l;
        } else if (nums[r] == target) {
            return r;
        }
        return -1;
    }
};

class Solution1 {
public:
    int search(vector<int>& nums, int target)
    {
        // unique in nums
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < nums[r]) {
                // location is in the lesser part
                if (nums[mid] <= target && target <= nums[r]) {
                    // this is in order
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else if (nums[l] < nums[mid]) {
                // location is in the larger part
                if (nums[l] <= target && target <= nums[mid]) {
                    // this is in order
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[l] == nums[mid]) {
                    ++l;
                }
                if (nums[r] == nums[mid]) {
                    --r;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    Solution sol;
    cout << sol.search(nums, 0) << endl;
    return 0;
}
// @lc code=end
