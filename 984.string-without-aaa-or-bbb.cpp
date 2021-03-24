/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

// @lc code=start
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        if (a == 0) {
            return string(b, 'b');
        } else if (b == 0) {
            return string(a, 'a');
        } else if (a == b) {
            return "ab" + strWithout3a3b(a - 1, b - 1);
        } else if (a > b) {
            return "aab" + strWithout3a3b(a - 2, b - 1);
        } else {
            return strWithout3a3b(a - 1, b - 2) + "abb";
        }
    }
};
// @lc code=end
int main()
{
    Solution sol;
    cout << sol.strWithout3a3b(4, 1) << endl;
    return 0;
}
