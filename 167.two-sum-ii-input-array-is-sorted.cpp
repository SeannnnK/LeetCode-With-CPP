/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
// amazon

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int n = numbers.size();
        if (n < 2) {
            return vector<int>();
        }
        for (int i = 0, j = n - 1; i != j;) {
            if (numbers[i] + numbers[j] < target) {
                ++i;
            } else if (numbers[i] + numbers[j] > target) {
                --j;
            } else {
                return {++i, ++j};
            }
        }
        return vector<int>();
    }
};

int main()
{
    Solution s;
    vector<int> numbers{2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(numbers, target);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end
