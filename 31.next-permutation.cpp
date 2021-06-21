/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.16%)
 * Likes:    5973
 * Dislikes: 1999
 * Total Accepted:    535K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such an arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascending order).
 *
 * The replacement must be in place and use only constant extra memory.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * Example 2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * Example 3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
// google

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Why the algo is so? draw a x axis and y axis to have a look
    void nextPermutation(vector<int>& nums)
    {
        /*
         * 1. find the rightmost index [i] that meet: nums[i] < nums[i + 1]
         * if not found then return directly
         * 2. fing the righmost index j that meet: nums[i] < nums[j]
         * 3. recverse the (i + 1) to end sub array 
         */
        int n = nums.size(), i, j;
        for (i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            swap(nums[i], nums[j]);
            // why reverse the remaining? becasue the conditon 1, we make this array small
            reverse(nums.begin() + i + 1, nums.end());
        }
    }

public:
    void printVec(const vector<int>& v) {
        for (const auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> inputs{{1, 2, 3}, {3, 2, 1}, {1, 1, 5}, {1}};
    for (auto& input : inputs) {
        sol.nextPermutation(input);
        sol.printVec(input);
    }

    return 0;
}
// @lc code=end
