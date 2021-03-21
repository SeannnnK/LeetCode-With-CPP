/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
// amazon
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.empty() || p.empty()) {
            return res;
        }
        vector<int> cnt(26);
        for (const auto& c : p) {
            ++cnt[c - 'a'];
        }

        for (int left = 0, right = 0; right < s.length(); ++right) {
            --cnt[s[right] - 'a'];
            while (left <= right && cnt[s[right] - 'a'] < 0) {
                ++cnt[s[left++] - 'a'];
            }
            if (right - left + 1 == p.size()) {
                res.push_back(left);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "abab", p = "ab";
    vector<int> res = sol.findAnagrams(s, p);
    for (const auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end

