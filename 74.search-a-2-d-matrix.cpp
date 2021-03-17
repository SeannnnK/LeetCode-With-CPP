/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r = row * col - 1;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (matrix[mid / col][mid % col] < target) {
                l = mid + 1;
            } else if (matrix[mid / col][mid % col] > target) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    Solution sol;
    cout << sol.searchMatrix(matrix, 3) << endl;
    return 0;
}
// @lc code=end

