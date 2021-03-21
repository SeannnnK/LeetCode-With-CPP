/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
// adobe | amazon | bloomberg | yelp
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       if (n == 0) {
           return 0;
       }
       vector<int> dict(256, -1);
       int maxLen = 0, start = -1;
       for (int i = 0; i < n; ++i) {
           if (dict[s[i]] > start) {
               start = dict[s[i]];
           }
           dict[s[i]] = i;
           maxLen = max(maxLen, i - start);
       }
       return maxLen;
    }
};

int main()
{
    string s = "pwwkew";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
// @lc code=end

