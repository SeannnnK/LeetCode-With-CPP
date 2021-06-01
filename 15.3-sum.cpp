/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
// adobe | amazon | bloomberg | facebook | microsoft

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        if (nums.empty() || nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int low = i + 1, high = nums.size() - 1, sum = 0 - nums[i];
                while (low < high) {
                    if (nums[low] + nums[high] == sum) {
                        res.push_back({nums[i], nums[low], nums[high]});

                        while (low < high && nums[low] == nums[low + 1]) {
                            ++low;
                        }

                        while (low < high && nums[high] == nums[high - 1]) {
                            --high;
                        }
                        ++low;
                        --high;
                    } else if (nums[low] + nums[high] < sum) {
                        ++low;
                    } else {
                        --high;
                    }
                }
            }
        }
        return res;
    }

public:
    void printRes(vector<vector<int>> res)
    {
        for (auto& level : res) {
            for (auto& num : level) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> res;
    vector<vector<int>> inputs{{-1, 0, 1, 2, -1, -4}, {}, {0}};
    for (auto& input : inputs) {
        res = sol.threeSum(input);
        sol.printRes(res);
        cout << "_____________" << endl;
    }
    return 0;
}
// @lc code=end
