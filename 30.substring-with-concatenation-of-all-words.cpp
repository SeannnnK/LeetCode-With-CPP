/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
// Unknown

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> res;
        if (words.empty()) {
            return res;
        }
        unordered_map<string, int> counts;

        for (const auto& word : words) {
            ++counts[word];
        }

        int m = s.size(), n = words.size(), len = words[0].size();
        // from begin to the last element that meets the total len is (n * len)
        for (int i = 0; i <= m - n * len; ++i) {
            unordered_map<string, int> seen;
            int j = 0;
            /*
             * use the hash map to judge that the two string is the same with the
             * order diff
             */
            while (j < n) {
                string sub = s.substr(i + j * len, len);
                if (counts[sub] > 0) {
                    ++seen[sub];
                    if (seen[sub] > counts[sub]) {
                        break;
                    }
                } else {
                    break;
                }
                ++j;
            }
            if (j == n) {
                res.push_back(i);
            }
        }
        return res;
    }

public:
    void printRes(vector<int>& res)
    {
        for (const auto& i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution sol;
    vector<pair<string, vector<string>>> inputs{
        {"wordgoodgoodgoodbestword", {"word", "good", "best", "word"}},
        {"barfoofoobarthefoobarman", {"bar", "foo", "the"}}};

    vector<int> res;
    for (auto& input : inputs) {
        res = sol.findSubstring(input.first, input.second);
        sol.printRes(res);
    }

    return 0;
}
// @lc code=end
