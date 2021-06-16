/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
// bloomberg | facebook | microsoft

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int slow = 1, fast = 1;
        while (fast < n) {
            if (nums[fast - 1] != nums[fast]) {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }

        return slow;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> vv{{1, 1, 2}, {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}};
    for (auto& v : vv) {
        cout << sol.removeDuplicates(v) << endl;
    }
    return 0;
}
// @lc code=end
