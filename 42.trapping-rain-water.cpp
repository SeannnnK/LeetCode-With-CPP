/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (52.26%)
 * Likes:    12336
 * Dislikes: 176
 * Total Accepted:    788.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 0 <= n <= 3 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */

// @lc code=start
// array | two-pointers | stack
// amazon | apple | bloomberg | google | twitter | zenefits

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int res = 0;
        int n = height.size();
        for (int i = 1; i < n - 1; ++i) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; --j) {
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < n; ++j) {
                max_right = max(max_right, height[j]);
            }
            res += min(max_left, max_right) - height[i];
        }
        return res;
    }
};

class Solution1 {
public:
    // dp
    int trap(vector<int>& height)
    {
        int res = 0;
        int n = height.size();
        if (n <= 0) {
            return res;
        }
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        for (int i = 0; i < n; ++i) {
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};

class Solution2 {
public:
    // mono decreasing stack
    int trap(vector<int>& height)
    {
        int n = height.size();
        int res = 0, i = 0;
        stack<int> st;
        while (i < n) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int tmp = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int dis = i - st.top() - 1;
                int interval_water = dis * (min(height[st.top()], height[i]) - height[tmp]);
                res += interval_water;
            }
            st.push(i);
            ++i;
        }
        return res;
    }
};

class Solution3 {
public:
    // two pointer
    int trap(vector<int>& height)
    {
        int res = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                // let right pos to be fixed, move the left
                if (height[left] < left_max) {
                    res += left_max - height[left];
                } else {
                    left_max = height[left];
                }
                ++left;
            } else {
                // left left to be fixed and move the right pos
                if (height[right] < right_max) {
                    res += right_max - height[right];
                } else {
                    right_max = height[right];
                }
                --right;
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> inputs{{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, {4, 2, 0, 3, 2, 5}};
    Solution sol;
    for (auto& input : inputs) {
        cout << sol.trap(input) << endl;
    }
    return 0;
}
// @lc code=end
