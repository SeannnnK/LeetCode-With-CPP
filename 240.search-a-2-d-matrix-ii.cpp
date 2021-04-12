/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
// amazon | apple | google
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1, col = matrix[0].size() - 1;
        int i = 0, j = col;
        while (i <= row  && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
                               {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
                               {18, 21, 23, 26, 30}};
    Solution sol;
    cout << sol.searchMatrix(matrix, 9) << endl;
    return 0;
}
// @lc code=end

