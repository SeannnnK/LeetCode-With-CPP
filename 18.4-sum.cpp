/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
// linkedin

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }

private:
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k)
    {
        vector<vector<int>> res;
        if (start == nums.size() || nums[start] * k > target || target > nums.back() * k) {
            return res;
        }
        if (k == 2) {
            return twoSum(nums, target, start);
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i] != nums[i - 1]) {
                auto tmp = kSum(nums, target - nums[i], i + 1, k - 1);
                for (auto& v : tmp) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(v), end(v));
                }
            }
        }
        return res;
    }

private:
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start)
    {
        vector<vector<int>> res;
        int low = start, high = nums.size() - 1;
        while (low < high) {
            int sum = nums[low] + nums[high];
            if (sum < target || low > start && nums[low] == nums[low - 1]) {
                ++low;
            } else if (sum > target || high < nums.size() - 1 && nums[high] == nums[high + 1]) {
                --high;
            } else {
                res.push_back({nums[low++], nums[high--]});
            }
        }
        return res;
    }

public:
    void printRes(vector<vector<int>> res)
    {
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < res[i].size(); ++j) {
                cout  << res[i][j] << " ";
            }
            cout << endl;
        }
    }

};

int main()
{
    Solution sol;
    vector<pair<vector<int>, int>> inputs{{{1, 0, -1, 0, -2, 2}, 0}, {{2, 2, 2, 2, 2}, 8}};
    for (auto& input : inputs) {
        cout << "***************************" << endl;
        vector<vector<int>> res = sol.fourSum(input.first, input.second);
        sol.printRes(res);
    }
    return 0;
}
// @lc code=end
