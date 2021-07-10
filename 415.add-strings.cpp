/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (49.13%)
 * Likes:    1969
 * Dislikes: 407
 * Total Accepted:    317.6K
 * Total Submissions: 643.8K
 * Testcase Example:  '"11"\n"123"'
 *
 * Given two non-negative integers, num1 and num2 represented as string, return
 * the sum of num1 and num2 as a string.
 *
 * You must solve the problem without using any built-in library for handling
 * large integers (such as BigInteger). You must also not convert the inputs to
 * integers directly.
 *
 *
 * Example 1:
 *
 *
 * Input: num1 = "11", num2 = "123"
 * Output: "134"
 *
 *
 * Example 2:
 *
 *
 * Input: num1 = "456", num2 = "77"
 * Output: "533"
 *
 *
 * Example 3:
 *
 *
 * Input: num1 = "0", num2 = "0"
 * Output: "0"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num1.length, num2.length <= 10^4
 * num1 and num2 consist of only digits.
 * num1 and num2 don't have any leading zeros except for the zero itself.
 *
 *
 */

// @lc code=start
// aribnb google

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int n1 = num1.size() - 1, n2 = num2.size() - 1, add = 0;
        string res = "";
        while (n1 >= 0 || n2 >= 0 || add) {
            int x = n1 >= 0 ? num1[n1--] - '0' : 0;
            int y = n2 >= 0 ? num2[n2--] - '0' : 0;
            int sum = x + y + add;
            res = to_string(sum % 10) + res;
            add = sum / 10;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<pair<string, string>> inputs{{"11", "123"}, {"456", "77"}, {"0", "0"}};
    for (auto& input : inputs) {
        cout << sol.addStrings(input.first, input.second) << endl;
    }
    return 0;
}
// @lc code=end
