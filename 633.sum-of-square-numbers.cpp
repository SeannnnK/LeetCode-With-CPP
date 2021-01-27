/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);

        while (left <= right) {
            long long cur = left * left + right * right;
            if (cur < c) {
                ++left;
            } else if (cur > c) {
                --right;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int c = 5;
    Solution s;
    cout << s.judgeSquareSum(c) << endl;
    return 0;
}
// @lc code=end