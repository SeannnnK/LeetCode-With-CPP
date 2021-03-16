/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
// linkedin | microsoft
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        dfs(res, nums, 0, nums.size());
        return res;
    }
private:
    // note: pass by value for nums:
    void dfs(vector<vector<int>>& res, vector<int> nums, int start, int end) {
        if (start == end - 1) {
            res.push_back(nums);
            return;
        }
        for (int k = start; k < end; ++k) {
            if (start != k && nums[start] == nums[k]) {
                continue;
            }
            swap(nums[start], nums[k]);
            dfs(res, nums, start + 1, end);
        }
        return;
    }
};

int main()
{
    vector<int> nums{1, 1, 2};
    Solution sol;
    vector<vector<int>> res = sol.permuteUnique(nums);
    for (const auto& level : res) {
        for (const auto& num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end