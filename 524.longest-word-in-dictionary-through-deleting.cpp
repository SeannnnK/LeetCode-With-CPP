/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for (auto & word : d) {
            int i = 0;
            for (auto c : s) {
                if (i < word.length() && c == word[i]) {
                    ++i;
                }
            }
            if (i == word.length() &&
                (word.length() > res.length() ||
                (word.length() == res.length() && word < res))) {
                    res = word;
                }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "abpcplea";
    vector<string> d{"ale", "apple", "monkey", "plea"};
    cout << sol.findLongestWord(s, d) << endl;
    return 0;
}
// @lc code=end