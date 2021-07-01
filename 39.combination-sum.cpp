/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
// snapchat | uber

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        int n = candidates.size();
        /* do the prune to reduce the time */
        sort(candidates.begin(), candidates.end());
        vector<int> p;
        search(candidates, 0, p, target, res, n);
        return res;
    }

private:
    void search(vector<int>& nums, int index, vector<int>& p, int target, vector<vector<int>>& res,
                int len)
    {
        if (target == 0) {
            res.push_back(p);
            return;
        }

        /* do the prune to reduce the time */
        for (int i = index; i < len && target - nums[i] >= 0; ++i) {
            p.push_back(nums[i]);
            search(nums, i, p, target - nums[i], res, len);
            p.pop_back();
        }
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
