/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
// twitter

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num)
    {
        string res;
        vector<string> M{"", "M", "MM", "MMM"};
        vector<string> C{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return res += (res + M[num / 1000] + C[num % 1000 / 100] + X[num % 100 / 10] + I[num % 10]);
    }
};

int main()
{
    vector<int> nums{3, 4, 9, 58, 1994};
    Solution sol;
    for (auto& num : nums) {
        cout << sol.intToRoman(num) << endl;
    }
    return 0;
}
// @lc code=end
