/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
// airbnb | palantir | yahoo

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i])) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 2, 3, 1};
    cout << sol.containsDuplicate(nums) << endl;
    return 0;
}
// @lc code=end