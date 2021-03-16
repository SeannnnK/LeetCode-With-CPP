/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
// snapchat | uber

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> p;
        search(candidates, 0, p, target, res);
        return res;
    }
private:
    void search(vector<int>& nums, int next, vector<int>& p, int target, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(p);
            return;
        }
        if (next == nums.size() || target - nums[next] < 0) {
            return;
        }
        
        p.push_back(nums[next]);
        search(nums, next, p, target - nums[next], res);
        p.pop_back();
        search(nums, next + 1, p, target, res);
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum(candidates, target);
    for (const auto& level : res) {
        for (const auto& num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end