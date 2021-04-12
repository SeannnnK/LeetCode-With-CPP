/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
// facebook | google | microsoft | twitter | yelp
#include <vector>
#include <iostream>
#include <utility>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        multiset<pair<int, int>> all;
        for (auto& p : buildings) {
            all.insert(make_pair(p[0], -p[2]));
            all.insert(make_pair(p[1], p[2]));
        }

        multiset<int> heights({0});
        vector<int> last{0, 0};
        for (const auto& p : all) {
            if (p.second < 0) {
                heights.insert(-p.second);
            } else {
                heights.erase(heights.find(p.second));
            }

            int maxValue = *heights.rbegin();
            if (last[1] != maxValue) {
                last[0] = p.first;
                last[1] = maxValue; 
                res.push_back(last);
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> b{{1, 3, 3}, {2, 4, 4}, {5, 8, 2}, {6, 7, 4}, {8, 9, 4}};
    Solution sol;
    vector<vector<int>> res;
    res = sol.getSkyline(b);
    for (const auto& row : res) {
        for (const auto& n : row) {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
// @lc code=end
