/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (30.13%)
 * Likes:    5433
 * Dislikes: 193
 * Total Accepted:    386.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = ""
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 * 
 * 
 */

// @lc code=start
// Unknown
// dp
#include <string>
#include <stack>

using namespace std;

class Solution1 {
    // brute force
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                string subStr = s.substr(i, j - i + 1);
                if (isValid(subStr)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
private:
    bool isValid(string& str) {
        stack<char> s;
        for (const auto& c : str) {
            if (c == '(') {
                s.push(c);
            } else if (!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                return false;
            }
        }

        return s.empty();
    }

};

class Solution2 {
public:
    // time O(n)
    // space O(n)
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        vector<int> dp(n, 0);

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                // dp[i] = dp[i - 2] + 2
                if (s[i - 1] == '(') {
                    dp[i] = ((i - 2) > 0 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    // dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]
                    dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                }
                res = max(res, dp[i]);
            }
        }

        return res;
    }
};

class Solution3 {
public:
    // time O(n)
    // space O(n)
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> index_stack; 
        // step1: which is to push ')'
        index_stack.push(-1);
        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                index_stack.push(i);
            } else {
                // step1 makes sure the stack is not empty
                index_stack.pop();
                if (index_stack.empty()) {
                    // also push the ')'
                    index_stack.push(i);
                } else {
                    res = max(res, i - index_stack.top());
                }
            }
        }

        return res;
    }
};

class Solution4 {
public:
    // time O(n)
    // space O(1)
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;

        int left = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left == right) {
                res = max(res, left + right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left == right) {
                res = max(res, left + right);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return res;
    }
};
// @lc code=end

