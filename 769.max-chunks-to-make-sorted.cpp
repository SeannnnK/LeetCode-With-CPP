/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
// unkonwn
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, cur_max = 0;
        for (int i = 0; i < arr.size(); ++i) {
            cur_max = max(cur_max, arr[i]);
            if (cur_max == i) {
                ++res;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr{4, 3, 2, 1, 0};
    cout << sol.maxChunksToSorted(arr) << endl;
    return 0;
}
// @lc code=end