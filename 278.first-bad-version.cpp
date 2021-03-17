/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include <iostream>

using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    return 0;
}
// @lc code=end

