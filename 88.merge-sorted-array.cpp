/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m < 0 && n < 0) {
            return;
        }
        int pos = m-- + n-- - 1;
        // trick, we can copy from the rear end.
        while (m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n]) {
                nums1[pos--] = nums1[m--];
            } else {
                nums1[pos--] = nums2[n--];
            }
        }
        // don't need to use while (m >= 0) since we copy to nums1.
        while (n >= 0) {
            nums1[pos--] = nums2[n--];
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    for (auto i : nums1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end