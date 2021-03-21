/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <vector>
#include <iostream>
// adobe | apple | dropbox | google | microsoft | yahoo | zenefits

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // i + j = m - i + n - j; or i + j = m - i + n - j + 1;
        // make sure m <= n, since j = (m + n + 1) / 2  - i;
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        // we add 0.5, so if it's a even number, it will not change, if it's
        // an odd number, it will go to the right position.
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        int i = 0, j = 0;
        int maxOfLeft = 0, minOfRight = 0;
        while (iMin <= iMax) {
            // i > 0 means j < n; i < m means j > 0;
           i = iMin + (iMax - iMin) / 2;
           j = halfLen - i;
           if (i < m && nums2[j - 1] > nums1[i]) {
               iMin = i + 1;
           } else if (i > 0 && nums1[i - 1] > nums2[j]) {
               iMax = i - 1;
           } else {
               // i is perfect
               if (i == 0) {
                   maxOfLeft = nums2[j - 1];
               } else if (j == 0) {
                   maxOfLeft = nums1[i - 1];
               } else {
                   maxOfLeft = max(nums1[i - 1], nums2[j - 1]);
               }

               if ((m + n) % 2 == 1) {
                   return maxOfLeft;
               }

               if (i == m) {
                   minOfRight = nums2[j];
               } else if (j == n) {
                   minOfRight = nums1[i];
               } else {
                   minOfRight = min(nums1[i], nums2[j]);
               }

               return (maxOfLeft + minOfRight) / 2.0;
           }
        }
        return 0.0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1{1, 2}, nums2{3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
// @lc code=end