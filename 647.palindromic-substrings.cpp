/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
// facebook | linkedin

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += extendSubstrings(s, i, i);
            count += extendSubstrings(s, i, i + 1);
        }
        return count;
    }

private:
    int extendSubstrings(string s, int l, int r)
    {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            ++count;
            --l;
            ++r;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    cout << sol.countSubstrings("aaa") << endl;
    return 0;
}
// @lc code=end

