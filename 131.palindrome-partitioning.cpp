/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
// bloomberg
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> p;
        dfs(s, 0, p, res);
        return res;
    }
private:
    void dfs(string& s, int start, vector<string>& p, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(p);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                p.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, p, res);
                p.pop_back();
            }
        }
    }
    bool isPalindrome(string& s,  int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "aab";
    Solution sol;
    vector<vector<string>> res = sol.partition(s);
    for (const auto& v : res) {
        for (const auto& s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end