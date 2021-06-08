/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
// google | uber | zenefits

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }

private:
    void helper(vector<string>& res, string str, int left, int right)
    {
        if (left == 0 && right == 0) {
            res.push_back(str);
        }
        if (left > 0) {
            helper(res, str + "(", left - 1, right);
        }
        if (left < right) {
            helper(res, str + ")", left, right - 1);
        }
    }

public:
    void printRes(vector<string>& res)
    {
        for (auto& s : res) {
            cout << s << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> v{3, 1};
    Solution sol;
    vector<string> res;
    for (auto& n : v) {
        res = sol.generateParenthesis(n);
        sol.printRes(res);
    }
    return 0;
}
// @lc code=end
