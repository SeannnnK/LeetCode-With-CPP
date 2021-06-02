/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
// amazon | dropbox | facebook | google | uber

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        vector<string> letter{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path = "";
        dfs(digits, 0, path, res, letter);
        return res;
    }

private:
    void dfs(string digits, int pos, string& path, vector<string>& res, vector<string>& letter)
    {
        if (pos == digits.size()) {
            res.push_back(path);
            return;
        }
        for (const auto& c : letter[digits[pos] - '0']) {
            path.push_back(c);
            dfs(digits, pos + 1, path, res, letter);
            path.pop_back();
        }
    }
};

int main()
{
    string digits = "23";
    Solution sol;
    vector<string> res = sol.letterCombinations(digits);
    for (const auto& str : res) {
        cout << str << endl;
    }
    return 0;
}
// @lc code=end
