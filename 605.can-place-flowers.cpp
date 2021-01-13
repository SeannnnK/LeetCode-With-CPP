/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); ++i) {
            // left and right are 1 and remember to deal with the edge condition
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0)
                && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                    flowerbed[i] = 1;
                    --n;
                }
            if (n <= 0) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> flowerbed{1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(flowerbed, 1) << endl;
    return 0;
}
// @lc code=end

