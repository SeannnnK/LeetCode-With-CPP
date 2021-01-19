/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty()) {
            return vector<vector<int>>();
        }

        int n = people.size();
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        for (const auto& p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> res = s.reconstructQueue(people);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}
// @lc code=end