/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
// Unknown
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> first; // <num, index>
        unordered_map<int, int> cnt; // <num, cnt>
        int degree = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (first.count(nums[i]) == 0) {
                first[nums[i]] = i;
            }
            if (++cnt[nums[i]] > degree) {
                degree = cnt[nums[i]];
                res = i - first[nums[i]] + 1;
            } else if (cnt[nums[i]] == degree) {
                res = min(res, i - first[nums[i]] + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 2, 2, 3, 1};
    cout << sol.findShortestSubArray(nums) << endl;
    return 0;
}
// @lc code=end