/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int n = nums.size();
        int left = 0, right = 0;

        for (right = 0; right < n; ++right) {
            if (nums[right] != val) {
                nums[left++] = nums[right];
            }
        }
        return left;
    }
};


class Solution1 {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int n = nums.size();
        int left = 0, right = n;
        
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                --right;
            } else {
                ++left;
            }
        }

        return left;
    }
};

int main()
{
    Solution sol;
    vector<pair<vector<int>, int>> vp{{{3, 2, 2, 3}, 3}, {{0, 1, 2, 2, 3, 0, 4, 2}, 2}};
    for (auto& p : vp) {
        cout << sol.removeElement(p.first, p.second) << endl;
    }
    return 0;
}
// @lc code=end
