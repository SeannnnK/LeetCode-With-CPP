/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
// Unknwn
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long a = labs(dividend);
        long b = labs(divisor);
        long res = 0;

        while (a >= b) {
            long x = b, m = 1;
            while (x << 1 <= a) {
                x <<= 1;
                m <<= 1;
            }
            a -= x;
            res += m;
        }

        return sign * res;
    }
};

int main()
{
    vector<pair<int, int>> v{{10, 3}, {7, -3}, {0, 1}, {1, 1}};
    Solution sol;
    for (auto& p : v) {
        cout << sol.divide(p.first, p.second);
        cout << endl;
    }
    return 0;
}
// @lc code=end
