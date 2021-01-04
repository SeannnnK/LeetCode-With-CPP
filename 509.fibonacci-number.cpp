/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int fn1 = 1, fn2 = 0;
        int fn = 0;
        for (int i = 2; i <= n; ++i) {
            fn = fn1 + fn2;
            fn2 = fn1;
            fn1 = fn;
        }
        return fn;
    }
};
// @lc code=end
int main()
{
    Solution s;
    cout << s.fib(4) << endl;
    return 0;
}
