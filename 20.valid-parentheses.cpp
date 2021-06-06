/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
// airbnb | amazon | bloomberg | facebook | google | microsoft | twitter | zenefits
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> sta;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sta.push(s[i]);
            } else {
                if (sta.empty()) {
                    return false;
                }
                char c = sta.top();
                if ((s[i] == '}' && c == '{') || (s[i] == ']' && c == '[') ||
                    (s[i] == ')' && c == '(')) {
                    sta.pop();
                } else {
                    return false;
                }
            }
        }
        return sta.empty();
    }
};

int main()
{
    string s = "()[]{}";
    Solution sol;
    cout << sol.isValid(s) << endl;
    return 0;
}
// @lc code=end
