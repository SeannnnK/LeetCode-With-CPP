/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
// google

#include <vector>
#include <iostream>
/*
 *   1130. Minimum Cost Tree From Leaf Values
 *   907. Sum of Subarray Minimums
 *   901. Online Stock Span
 *   856. Score of Parentheses
 *   503. Next Greater Element II
 *   496. Next Greater Element I
 *   84. Largest Rectangle in Histogram
 *   42. Trapping Rain Water
 */

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack, res(n, -1);
        for (int i = 0; i < n * 2; ++i) {
            while (!stack.empty() && nums[stack.back()] < nums[i % n]) {
                res[stack.back()] = nums[i % n];
                stack.pop_back();
            }
            stack.push_back(i % n);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 2, 3, 4, 3};
    vector<int> res;
    res = sol.nextGreaterElements(nums);
    for (const auto& n : res) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end