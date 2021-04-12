/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
// facebook | google

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // why not using sorting? since there may have dup elelments
        unordered_set<int> hash;
        for (const auto& n : nums) {
            hash.insert(n);
        }
        int res = 0;
        while (!hash.empty()) {
            int n = *hash.begin();
            hash.erase(n);
            int next = n + 1, prev = n - 1;

            while (hash.count(next)) {
                hash.erase(next++);
            }
            while (hash.count(prev)) {
                hash.erase(prev--);
            }

            res = max(res, next - prev - 1);
        }
        return res;
    }
};

int main()
{
    vector<int> nums{100, 4, 200, 1, 3, 2};
    Solution sol;
    int res = sol.longestConsecutive(nums);
    cout << res << endl;
    return 0;
}
// @lc code=end