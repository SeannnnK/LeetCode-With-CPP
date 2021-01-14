/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <vector> 
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        if (s.empty()) {
            return vector<int>();
        }

        vector<int> letterHash(26, 0);
        vector<int> res;

        for (int i = 0; i < s.size(); ++i) {
            letterHash[s[i] - 'a'] = i;
        }

        int start = 0, last = 0;

        for (int i = 0; i < s.size(); ++i) {
            last = max(letterHash[s[i] - 'a'], last);
            if (last == i) {
                res.push_back(last - start + 1);
                start = last + 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    string str("ababcbacadefegdehijhklij");
    auto res = s.partitionLabels(str);
    for (auto iter : res) {
        cout << iter << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end

