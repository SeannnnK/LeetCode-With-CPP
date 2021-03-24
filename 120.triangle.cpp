/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> mini(triangle[triangle.size() - 1]);
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                mini[j] = triangle[i][j] + min(mini[j], mini[j + 1]);
            }
        }
        return mini[0];
    }
};
// @lc code=end

int main()
{
    vector<vector<int>> triange {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    cout << sol.minimumTotal(triange) << endl;
    return 0;
}