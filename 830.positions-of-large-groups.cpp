/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        vector<vector<int>> res;
        for (int i = 0, j = 0; j < n; ++j) {
            // if j is the last element or the number changes
            if (j == n - 1 || s[j] != s[j + 1]) {
                if (j - i >= 2) {
                    res.emplace_back(vector<int>{i, j});
                }
                i = j + 1;
            }
        }
        return res;
    }
};

int main()
{
    string str("abbxxxxzzy");
    Solution s;
    vector<vector<int>> res;
    res = s.largeGroupPositions(str);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end