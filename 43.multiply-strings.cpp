/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (35.44%)
 * Likes:    2729
 * Dislikes: 1090
 * Total Accepted:    385.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 *
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Constraints:
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 *
 *
 */

// @lc code=start
// facebook | twitter

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution1 {
public:
    string multiply(string num1, string num2)
    {
        string res;
        if (num1 == "0" || num2 == "0") {
            return res;
        }

        int n1 = num1.size() - 1, n2 = num2.size() - 1;
        for (int i = n2; i >= 0; --i) {
            string s = "";
            int add = 0;
            for (int j = n2; j > i; --j) {
                s = s + "0";
            }
            int y = num2.at(i) - '0';
            for (int j = n1; j >= 0; --j) {
                int x = num1[j] - '0';
                int multi = x * y + add;
                s = s + to_string(multi % 10);
                add = multi / 10;
            }
            if (add) {
                s += to_string(add);
            }
            reverse(s.begin(), s.end());
            res = addString(s, res);
        }
        return res;
    }

private:
    string addString(string& num1, string& num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string res;
        while (i >= 0 || j >= 0 || add) {
            int x = i >= 0 ? num1.at(i--) - '0' : 0;
            int y = j >= 0 ? num2.at(j--) - '0' : 0;
            int sum = x + y + add;
            res = to_string(sum % 10) + res;
            add = sum / 10;
        }
        return res;
    }
};

class Solution {
public:
    string multiply(string num1, string num2)
    {
        string res;
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int n1 = num1.size(), n2 = num2.size();
        vector<int> multi(n1 + n2);
        for (int i = n1 - 1; i >= 0; --i) {
            int x = num1[i] - '0';
            for (int j = n2 - 1; j >= 0; --j) {
                int y = num2[j] - '0';
                multi[i + j + 1] += x * y;
            }
        }

        for (int i = n1 + n2 - 1; i > 0; --i) {
            multi[i - 1] += multi[i] / 10;
            multi[i] = multi[i] % 10;
        }
        if (multi[0] != 0) {
            res = res + to_string(multi[0]);
        }
        for (int i = 1; i <= n1 + n2 - 1; ++i) {
            res = res + to_string(multi[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<pair<string, string>> inputs{{"9", "99"}, {"123", "456"}};
    for (auto& input : inputs) {
        cout << sol.multiply(input.first, input.second) << endl;
    }
    return 0;
}
// @lc code=end
