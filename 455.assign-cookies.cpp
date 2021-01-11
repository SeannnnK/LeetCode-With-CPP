/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size(), i = 0;
        int m = s.size(), j = 0;
        while (i < n && j < m) {
            if (g[i] <= s[j]) {
                ++i;
            }
            ++j;
        }
        return i;
    }
};

int main()
{
    Solution myS;
    vector<int> g{1, 2};
    vector<int> s{1, 2, 3};
    cout << myS.findContentChildren(g, s) << endl;
    return 0;
}
// @lc code=end