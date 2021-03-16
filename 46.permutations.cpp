/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
// linkedin | microsoft

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> level;
        dfs(nums, level, res, 0);
        return res;
    }
private:
    void dfs(vector<int>& nums, vector<int>& level, vector<vector<int>>& res, int pos) {
        if (pos == nums.size()) {
            res.push_back(level);
            return;
        }
        for (int i = 0; i <= level.size(); ++i) {
            // insert before the pos
            level.insert(level.begin() + i, nums[pos]);
            dfs(nums, level, res, pos + 1);
            level.erase(level.begin() + i);
        }
        return;
    }
public:
    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>> res;
        dfs2(res, nums, 0);
        return res;
    }
private:
    void dfs2(vector<vector<int>>& res, vector<int>& nums, int pos) {
        if (pos == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); ++i) {
            swap(nums[pos], nums[i]);
            dfs2(res, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
        return;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution sol;
    vector<vector<int>> res = sol.permute(nums);
    for (const auto& level : res) {
        for (const auto& num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end