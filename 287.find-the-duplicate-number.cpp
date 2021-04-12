/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
// bloomberg
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (const auto& num : nums) {
            if (nums[abs(num) - 1] < 0) {
                return  abs(num);
            }
            nums[abs(num) - 1] *= -1;
        }
        return 0;
    }
};

class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return -1;
        }
        int slow = nums[0], fast = nums[0];
        // why we use do while loop? because above assignment has let the slow == fast
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 3, 4, 2, 2};
    cout << sol.findDuplicate(nums) << endl;
    return 0;
}
// @lc code=end