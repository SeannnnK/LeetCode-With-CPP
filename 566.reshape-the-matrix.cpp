/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
// mathworks
#include <vector>
#include <iostream>

using namespace std;

// c is more easy I think. since in c the matrix is continous, we can operate on the pointer directly.
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = m > 0 ? nums[0].size() : 0;
        if (m * n != r * c) {
            return nums;
        }
        int cnt = 0;
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = nums[cnt / n][cnt % n];
                ++cnt;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> nums{{1, 2}, {3, 4}};
    // please notice the vector is not same as the c, it is not continous.
    cout << &nums[0][0] << endl; // 0x7fb1a1c05aa0
    cout << &nums[0][1] << endl; // 0x7fb1a1c05aa4
    cout << &nums[1][0] << endl; // 0x7fb1a1c05ab0
    cout << &nums[1][1] << endl; // 0x7fb1a1c05ab4
    vector<vector<int>> res;
    res = sol.matrixReshape(nums, 1, 4);
    for (const auto& level : res) {
        for (const auto& n : level) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end
