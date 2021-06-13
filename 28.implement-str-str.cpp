/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
// apple | facebook | microsoft | pocketgems

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();

        for (int i = 0; i + n <= m; ++i) {
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};

class Solution1 {
public:
    // KMP
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if (n == 0) {
            return 0;
        }
        // i is the needle's index and j is the len of the prefix len
        // construct the prefix table
        vector<int> pi(n, 0);
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                ++j;
            }
            pi[i] = j;
        }

        // do comapre strstr
        for (int i = 0, j = 0; i < m; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                ++j;
            }
            if (j == m) {
                return i - n + 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<pair<string, string>> vs{{"hello", "ll"}, {"aaaaa", "bba"}, {"", ""}};
    for (auto& p : vs) {
        cout << sol.strStr(p.first, p.second) << endl;
    }
    return 0;
}
// @lc code=end
