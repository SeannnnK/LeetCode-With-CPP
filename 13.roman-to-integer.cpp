/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
// bloomberg | facebook | microsoft | uber | yahoo

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> numMap{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                        {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && numMap[s[i]] > numMap[s[i - 1]]) {
                res += numMap[s[i]] - 2 * numMap[s[i - 1]];
            } else {
                res += numMap[s[i]];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> strs{"III", "IV", "IX", "LVIII", "MCMXCIV"};
    for (auto& s : strs) {
        cout << sol.romanToInt(s) << endl;
    }
    return 0;
}
// @lc code=end
