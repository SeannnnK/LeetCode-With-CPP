/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        int pos = points[0][1];
        int cnt = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= pos) {
                continue;
            }
            ++cnt;
            pos = points[i][1];
        }

        return cnt;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}
// @lc code=end