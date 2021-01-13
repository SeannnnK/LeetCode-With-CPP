/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            // left to right increasing
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            // right to left increasing
            if (ratings[i] < ratings[i - 1]) {
                // monotony but need to consider when it's in
                // the interval of increading and decreasing like 1, 3, 2
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main()
{
    Solution s;
    vector<int> ratings{1, 3, 2, 2, 1};
    cout << s.candy(ratings) << endl;
    return 0;
}
// @lc code=end