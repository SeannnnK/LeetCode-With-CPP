/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
// amazon | google | zenefits
#include <vector>
#include <utility>
#include <iostream>
#include <queue> // priority_queue

using namespace std;

// 1. prirority queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }

        vector<int> ans = {q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            // which is the key point, the element is located out
            // of the window.
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.emplace_back(q.top().first);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, 3);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end