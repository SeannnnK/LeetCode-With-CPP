/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return aux(s, left, right - 1) || aux(s, left + 1, right);
            }
            ++left;
            --right;
        }
        return true;
    }
private:
    bool aux(string s, int left, int right) {
       while (left < right) {
           if (s[left] != s[right]) {
               return false;
           }
           ++left;
           --right;
       }
       return true;
    }
};

int main()
{
    Solution s;
    cout << s.validPalindrome("abca") << endl;
    return 0;
}
// @lc code=end

