/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
// Unknown
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there
// are k odd numbers on it.  Return the number of nice sub - arrays.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // two pass
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k)
    {
        int i = 0, n = nums.size(), res = 0;
        for (int j = 0; j < n; ++j) {
            k -= nums[j] % 2;
            while (k < 0) {
                k += nums[i++] % 2;
            }
            res += j - i + 1;
        }
        return res;
    }
    // one pass
public:
    int numberOfSubarrays2(vector<int>& nums, int k)
    {
        int i = 0, n = nums.size(), res = 0, count = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] % 2) {
                --k;
                count = 0;
            }
            while (k == 0) {
                k += nums[i++] % 2;
                ++count;
            }
            res += count;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    cout << sol.numberOfSubarrays2(nums, k) << endl;
    return 0;
}
// @lc code=end
