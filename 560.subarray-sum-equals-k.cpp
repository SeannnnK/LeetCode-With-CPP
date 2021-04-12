/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
// google
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash{{0, 1}};
        int psum = 0, count = 0;
        for (const auto& num : nums) {
            psum += num;
            count += hash[psum - k];
            ++hash[psum];
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 1, 1};
    cout << sol.subarraySum(nums, 2) << endl;
    return 0;
}
// @lc code=end