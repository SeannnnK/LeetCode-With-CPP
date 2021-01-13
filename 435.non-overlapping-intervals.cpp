/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
                return a[1] < b[1];
            });
        
        int res = 0, prev = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prev) {
                ++res;
            } else {
                prev = intervals[i][1];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
// @lc code=end

