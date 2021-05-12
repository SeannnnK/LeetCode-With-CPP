/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
// amazon | bloomberg | microsoft
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        int maxLen = 0;
        int start = -1;
        if (s.size() < 2) {
            return s;
        }
        for (int i = 0; i < s.size() - 1; ++i) {
            extendSubstrings(s, i, i, start, maxLen);
            extendSubstrings(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }

private:
    void extendSubstrings(string s, int i, int j, int& start, int& maxLen)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
        }
        if (maxLen < j - i - 1) {
            maxLen = j - i - 1;
            start = i + 1;
        }
    }
};

// dp solution
class Solution2 {
public:
    string longestPalindrome(string s)
    {
        // dp[i][j] stands for the substr s(i, j) can be a pralindrome or not
        // transform equation: dp[i][j] = dp[i + 1][j - 1] if s[i] == s[j] and false otherwise
        int n = s.size();
        string res;
        if (n < 2) {
            return s;
        }
        bool dp[n][n];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i + 1][j - 1]);
                if (dp[i][j] && (j - i + 1 > res.size() || res.empty())) {
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    Solution2 sol2;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl;
    cout << sol2.longestPalindrome(s) << endl;
    return 0;
}
// @lc code=end
