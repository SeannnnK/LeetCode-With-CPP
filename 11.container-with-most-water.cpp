/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
// bloomberg

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int res = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                ++i;
            } else if (height[i] > height[j]) {
                --j;
            } else {
                ++i;
                --j;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> heights{{1, 8, 6, 2, 5, 4, 8, 3, 7}, {1, 1}, {4, 3, 2, 1, 4}, {1, 2, 1}};
    for (auto& height : heights) {
        cout << sol.maxArea(height) << endl;
    }
    return 0;
}
// @lc code=end
