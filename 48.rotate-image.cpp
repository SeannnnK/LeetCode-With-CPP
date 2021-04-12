/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
// amazon | apple | microsoft
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 2}, {3, 4}};
    Solution sol;
    sol.rotate(matrix);
    for (const auto& row : matrix) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end

