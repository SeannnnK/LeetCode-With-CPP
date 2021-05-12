/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
// Unknown

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        int n = s.size(), i = 0;
        vector<string> v(numRows, "");
        
        while (i < n) {
            for (int j = 0; j < numRows && i < n; ++j) {
                v[j].push_back(s[i++]);
            }
            for (int j = numRows - 2; j > 0 && i < n; --j) {
                v[j].push_back(s[i++]);
            }
        }
        string res;
        for (int i = 0; i < numRows; ++i) {
            res += v[i];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.convert("helloworld", 3) << endl;
    return 0;
}
// @lc code=end
