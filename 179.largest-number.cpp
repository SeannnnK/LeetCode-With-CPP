/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &i, const int &j) { 
            return to_string(i) + to_string(j) > to_string(j) + to_string(i);
        });
        string res;
        for (const int& num : nums) {
            res.append(to_string(num));
        }
        if (!res.empty() && res[0] == '0') {
            return "0";
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{3, 30, 34, 5, 9};
    cout << sol.largestNumber(nums) << endl;
    return 0;
}
// @lc code=end

