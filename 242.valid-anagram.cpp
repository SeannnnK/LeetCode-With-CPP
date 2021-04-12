/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
// amazon | uber | yelp

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int len = s.size();
        vector<int> cnt(26, 0);
        if (len != t.size()) {
            return false;
        }

        for (int i = 0; i < len; ++i) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "anagram", t = "nagatam";
    Solution sol;
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}
// @lc code=end

