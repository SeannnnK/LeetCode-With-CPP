/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
// palantir
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) : psum(nums.size() + 1, 0) {
        // partial_sum since c++20;
        psum[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            psum[i + 1] = nums[i] + psum[i];
        }
    }
    
    int sumRange(int left, int right) {
        return psum[right + 1] - psum[left];
    }
private:
    vector<int> psum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
int main()
{
    vector<int> nums{-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(1, 5) << endl;
    return 0;
}
// @lc code=end