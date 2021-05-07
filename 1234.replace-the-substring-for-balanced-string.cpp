/*
 * @lc app=leetcode id=1234 lang=cpp
 *
 * [1234] Replace the Substring for Balanced String
 */

// @lc code=start
// Unknown
// You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.  A string is
// said to be balanced if each of its characters appears n/4 times where n is the length of the
// string.  Return the minimum length of the substring that can be replaced with any other string of
// the same length to make the original string s balanced.  Return 0 if the string is already
// balanced

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int balancedString(string s)
    {
        unordered_map<int, int> m;
        int n = s.size(), res = n, i = 0, k = n / 4;
        for (int i = 0; i < n; ++i) {
            ++m[s[i]];
        }
        if (m['Q'] <= k && m['E'] <= k && m['W'] <= k && m['R'] <= k) {
            return 0;
        }
        for (int j = 0; j < n; ++j) {
            --m[s[j]];
            // notice there is a condition i < n you can see the "QWER" case i will bigger than j
            // but we have the condition above to return 0
            while (m['Q'] <= k && m['E'] <= k && m['W'] <= k && m['R'] <= k) {
                res = min(res, j - i + 1);
                ++m[s[i++]];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.balancedString("QQQE") << endl;
    return 0;
}
// @lc code=end
