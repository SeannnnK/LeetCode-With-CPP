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
        if (prices.empty()) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
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

