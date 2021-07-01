/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (50.89%)
 * Likes:    3064
 * Dislikes: 94
 * Total Accepted:    424.6K
 * Total Submissions: 832.6K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

// @lc code=start: backtrack
// snapchat

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, target, path, res, 0, n);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& res,
             int index, int n)
    {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        /* do the prune */
        for (int i = index; i < n && target - candidates[i] >= 0; ++i) {
            // how to reduce the duplicates? we just skip the dup in candidates
            if (i && candidates[i] == candidates[i - 1] && i > index) {
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], path, res, i + 1, n);
            path.pop_back();
        }
        return;
    }

public:
    void print(vector<vector<int>>& input)
    {
        for (auto& ii : input) {
            for (auto& i : ii) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Solution sol;
    vector<pair<vector<int>, int>> inputs{{{10, 1, 2, 7, 6, 1, 5}, 8}, {{2, 5, 2, 1, 2}, 5}};
    vector<vector<int>> res;
    for (auto& input : inputs) {
        res = sol.combinationSum2(input.first, input.second);
        sol.print(res);
    }
    return 0;
}
// @lc code=end
