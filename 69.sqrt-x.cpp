/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return x;
        }

        int l = 1, r = x;
        int mid = 0, sqrt = 0;

        while (l <= r) {
            mid = l + (r - l) / 2;
            sqrt = x / mid;
            if (mid == sqrt)  {
                return mid;
            } else if (mid < sqrt) {
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};

int main()
{
    Solution sol;
    cout << sol.mySqrt(8) << endl;
    return 0;
}
// @lc code=end

