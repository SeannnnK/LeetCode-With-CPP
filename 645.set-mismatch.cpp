/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
// amazon
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, -1);
        for (const auto& num : nums) {
            if (nums[abs(num) - 1] < 0) {
                // twice
                res[0] = abs(num);
            } else {
                nums[abs(num) - 1] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res[1] = i + 1;
                break;
            }
        }
        return res;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<int> nums{1, 2, 2, 4};
    vector<int> res = sol.findErrorNums(nums);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}