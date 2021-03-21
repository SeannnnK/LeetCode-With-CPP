/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
// microsoft
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cur(26), goal(26);
        for (char c : s1) {
            ++goal[c - 'a'];
        }
        for (int i = 0; i < s2.size(); ++i) {
            ++cur[s2[i] - 'a'];
            if (i >= s1.size()) {
                --cur[s2[i - s1.size()] - 'a'];
            }
            if (goal == cur) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    string s1 = "ab", s2 = "eidbaooo";
    Solution sol;
    cout << sol.checkInclusion(s1, s2) << endl;
    return 0;
}
// @lc code=end