/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
// Unknown
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();

        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);

        // left coloum;
        for (int i = 1; i < m; ++i) {
            pre[i] = pre[i - 1] + grid[i][0];
        }

        for (int j = 1; j < n; ++j) {
            // iterate the column until we reach the final
            cur[0] = pre[0] + grid[0][j];
            for (int i = 1; i < m; ++i) {
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            }
            pre = cur;
        }

        return pre[m - 1];
    }
};

class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();

        vector<int> cur(m, grid[0][0]);

        // left coloumn;
        for (int i = 1; i < m; ++i) {
            cur[i] = cur[i - 1] + grid[i][0];
        }

        // for every coloumn
        for (int j = 1; j < n; ++j) {
            // iterate the column until we reach the final
            cur[0] += grid[0][j];
            for (int i = 1; i < m; ++i) {
                // cur[i] is the same with the pre[i]
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
            }
        }

        return cur[m - 1];
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution sol;
    Solution1 sol1;
    Solution2 sol2;
    cout << sol.minPathSum(grid) << endl;
    cout << sol1.minPathSum(grid) << endl;
    cout << sol2.minPathSum(grid) << endl;
    return 0;
}
// @lc code=end
