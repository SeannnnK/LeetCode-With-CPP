/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (34.42%)
 * Likes:    6193
 * Dislikes: 1050
 * Total Accepted:    506.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array nums, find the smallest missing positive
 * integer.
 *
 * You must implement an algorithm that runs in O(n) time and uses constant
 * extra space.
 *
 *
 * Example 1:
 * Input: nums = [1,2,0]
 * Output: 3
 * Example 2:
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Example 3:
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */

// @lc code=start
// Unknown

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        // 1. remove the minus num
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        // 2. let the index to be minus
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        // 3. return the first index of num which is minus
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

class Solution1 {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
                // printVec(nums);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

private:
    void printVec(vector<int>& nums)
    {
        for (auto& n : nums) {
            cout << n << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> inputs{{1, 2, 0}, {3, 4, -1, 1}, {7, 8, 9, 11, 12}};
    for (auto& input : inputs) {
        cout << sol.firstMissingPositive(input) << endl;
    }
    vector<int> nums{3, 4, -1, 1};
    return 0;
}
// @lc code=end
