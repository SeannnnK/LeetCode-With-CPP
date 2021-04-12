/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
// Unknown
#include <vector>
#include <iostream>

using namespace std;
// why we not using the i in [i1, i2], j in [j1, j2] then calc the sum?
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        /*
         * dp, the status transition equation:
         * integral[i][j] = integral[i - 1][j] + integral[i][j- 1] - integral[i - 1][j - 1] + matrix[i][j];
         * then the result will be calculated by integral[row2 + 1][col2 + 1] - integral[row2 + 1][col1] - integral[row1[col2 + 1] + integral[row1][col1]
         */
        int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0;
        integral = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            // here I know why the integral is one bigger size than matrix, you can see we use i - 1, which will
            // reducing the complex condition
            for (int j = 1; j <= n; ++j) {
                integral[i][j] = integral[i - 1][j] + integral[i][j - 1] + matrix[i - 1][j - 1] - integral[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return integral[row2 + 1][col2 + 1] - integral[row2 + 1][col1] - integral[row1][col2 + 1] + integral[row1][col1];
    }

private:
    vector<vector<int>> integral;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
int main()
{
    vector<vector<int>> matrix{{3, 0, 1, 4, 2},
                               {5, 6, 3, 2, 1},
                               {1, 2, 0, 1, 5},
                               {4, 1, 0, 1, 7},
                               {1, 0, 3, 0, 5}};
    NumMatrix* obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2, 1, 4, 3) << " ";
    cout << obj->sumRegion(1, 1, 2, 2) << " ";
    cout << obj->sumRegion(1, 2, 2, 4) << endl;
    delete(obj);
    return 0;
}
// @lc code=end