// facebook

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> level;
        backtrack(nums, 0, level, res);
        return res;
    }
private:
    void backtrack(vector<int>& nums, int i, vector<int>& level, vector<vector<int>>& res) {
        res.push_back(level);
        for (int j = i; j < nums.size(); ++j) {
            if (j == i || nums[j - 1] != nums[j]) {
                level.push_back(nums[j]);
                backtrack(nums, j +  1, level, res);
                level.pop_back();
            }
        }
    }
public:
    // iterative
    vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> level;
        for (int i = 0, n = 0; i < nums.size(); ++i) {
            int j = (i != 0 || nums[j] != nums[j - 1]) ? 0 : n;
            n = level.size();
            for (; j < n; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{1, 2, 2};
    Solution sol;
    vector<vector<int>> res = sol.subsetsWithDup(nums);
    for (const auto& level : res) {
        for (const auto& num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}