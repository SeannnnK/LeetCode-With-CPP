/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
// apple | bloomberg

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        int tmp = 0;
        int res = 0;
        while (x) {
            if (res > INT_MAX / 10 || res < INT_MIN / 10) {
                return 0;
            }
            res = res * 10 + x % 10;
            x = x / 10;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int x1 = 2147483647;
    int x2 = 210;
    int x3 = 123;
    int x4 = -123;
    int x5 = -2147483648;
    vector<int> v{x1, x2, x3, x4, x5};
    for (int i = 0; i < v.size(); ++i) {
        cout << sol.reverse(v[i]) << endl;
    }
    return 0;
}
// @lc code=end
