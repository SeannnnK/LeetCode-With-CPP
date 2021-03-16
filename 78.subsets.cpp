/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
// amazon | bloomberg | facebook | uber
// @lc code=start
// https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i) {
            size_t size = res.size();
            for (size_t j = 0; j < size; ++j) {
                res.emplace_back(res[j]);
                res.back().emplace_back(nums[i]);
            }
        }
        return res;
    }
public:
    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> level;
        backtrack(nums, 0, level, res);
        return res;
    }
private:
    void backtrack(vector<int>& nums, int i, vector<int>& level, vector<vector<int>>& res) {
        res.push_back(level);
        for (int j = i; j < nums.size(); ++j) {
            level.push_back(nums[j]);
            backtrack(nums, j + 1, level, res);
            level.pop_back();
        }
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution sol;
    vector<vector<int>> res = sol.subsets(nums);
    for (const auto& row : res) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    res = sol.subsets2(nums);
    for (const auto& row : res) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end
