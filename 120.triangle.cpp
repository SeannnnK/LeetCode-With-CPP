/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
// Unknown


#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        if (triangle.size() == 0 || triangle[0].size() == 0) {
            return 0;
        }

        // bottom to up
        vector<vector<int>> mini(triangle.size(), triangle.back());
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                mini[i][j] = triangle[i][j] + min(mini[i + 1][j], mini[i + 1][j + 1]);
            }
        }

        return mini[0][0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        if (triangle.size() == 0 || triangle[0].size() == 0) {
            return 0;
        }

        // bottom to up
        vector<int> mini(triangle[triangle.size() - 1]);
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                mini[j] = triangle[i][j] + min(mini[j], mini[j + 1]);
            }
        }

        return mini[0];
    }
};

int main()
{
    vector<vector<int>> triange{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    Solution1 sol1;
    cout << sol1.minimumTotal(triange) << endl;
    cout << sol.minimumTotal(triange) << endl;
    return 0;
}
// @lc code=end
