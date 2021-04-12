/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
// apple | linkedin | twitter
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> hash;
        int max_count = 0, same = 1, same_x = 1;
        for (int i = 0; i < points.size(); ++i) {
            same = 1;
            same_x = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0]) {
                    ++same_x;
                    if (points[i][1] == points[j][1]) {
                        ++same;
                    }
                } else {
                    double dx = points[i][0] - points[j][0];
                    double dy = points[i][1] - points[j][1];
                    ++hash[dy / dx];
                }
            }
            max_count = max(max_count, same_x);
            for (const auto& item : hash) {
                max_count = max(max_count, same + item.second);
            }
            hash.clear();
        }
        return max_count;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> p1{{0, 0}, {4, 5}, {7, 8}, {8, 9}, {5, 6}, {3, 4}, {1, 1}};
    cout << sol.maxPoints(p1) << endl;
    vector<vector<int>> p{{1, 2}, {1, 4}, {2, 4}, {2, 1}, {3, 6}};
    cout << sol.maxPoints(p) << endl;
    vector<vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << sol.maxPoints(points) << endl;
    return 0;
}
// @lc code=end
