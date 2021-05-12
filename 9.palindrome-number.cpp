/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
// Unknown

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reverse_number = 0;
        while (x > reverse_number) {
            reverse_number = 10 * reverse_number + x % 10;
            x /= 10;
        }
        return (reverse_number / 10 == x) || (reverse_number == x);
    }
};

int main()
{
    Solution sol;
    vector<int> v{121, 1221, -7887, 0, 1234, 120};
    for (int i = 0; i < v.size(); ++i) {
        cout << sol.isPalindrome(v[i]) << endl;
    }
    return 0;
}
// @lc code=end
