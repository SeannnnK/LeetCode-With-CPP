/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
       int len = s.size();
       if (!len) {
           return;
       }
       int i = 0, j = len - 1;
       while (i < j) {
           swap(s[i++], s[j--]);
       }
    }
};

int main()
{
    Solution sol;
    vector<char> s{'h', 'e', 'l', 'l', 'o', 't'};
    sol.reverseString(s);
    for (auto & c : s) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end

