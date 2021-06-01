/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
// yelp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) {
            return "";
        }
        for (int i = 0; i < strs[0].size(); ++i) {
            for (const auto& str : strs) {
                if (i >= str.size() || strs[0][i] != str[i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> inputs{{"flower", "flow", "flight"}, {"dog", "racecar", "car"}};
    for (auto& input : inputs) {
        cout << sol.longestCommonPrefix(input) << endl;
    }
    return 0;
}
// @lc code=end
