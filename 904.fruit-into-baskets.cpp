/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
// Unknown
// "Start from any index, we can collect at most two types of fruits. What is the maximum amount"
// find the max length of the the array, which only can have 2 different value

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree)
    {
        int i = 0, n = tree.size(), res = 0;
        unordered_map<int, int> m;
        for (int j = 0; j < n; ++j) {
            ++m[tree[j]];
            while (m.size() > 2) {
                if (--m[tree[i]] == 0) {
                    m.erase(tree[i]);
                }
                ++i;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> tree{1, 2, 3, 2, 2};
    cout << sol.totalFruit(tree) << endl;
    return 0;
}
// @lc code=end
