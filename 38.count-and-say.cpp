/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Medium (46.70%)
 * Likes:    583
 * Dislikes: 1827
 * Total Accepted:    520K
 * Total Submissions: 1.1M
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 *
 *
 * countAndSay(1) = "1"
 * countAndSay(n) is the way you would "say" the digit string from
 * countAndSay(n-1), which is then converted into a different digit string.
 *
 *
 * To determine how you "say" a digit string, split it into the minimal number
 * of groups so that each group is a contiguous section all of the same
 * character. Then for each group, say the number of characters, then say the
 * character. To convert the saying into a digit string, replace the counts
 * with a number and concatenate every saying.
 *
 * For example, the saying and conversion for digit string "3322251":
 *
 * Given a positive integer n, return the n^th term of the count-and-say
 * sequence.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: "1"
 * Explanation: This is the base case.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4
 * Output: "1211"
 * Explanation:
 * countAndSay(1) = "1"
 * countAndSay(2) = say "1" = one 1 = "11"
 * countAndSay(3) = say "11" = two 1's = "21"
 * countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 30
 *
 *
 */

// @lc code=start
// facebook

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        if (n < 1) {
            return "";
        }
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); ++i) {
                int cnt = 1;
                while ((i + 1 < res.size()) && res[i] == res[i + 1]) {
                    ++cnt;
                    ++i;
                }
                cur += (to_string(cnt) + res[i]);
            }
            res = cur;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> input{1, 2, 3, 4};
    for (auto& i : input) {
        cout << sol.countAndSay(i) << endl;
    }
    return 0;
}
// @lc code=end
