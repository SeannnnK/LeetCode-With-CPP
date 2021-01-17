/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
// @lc code=end

