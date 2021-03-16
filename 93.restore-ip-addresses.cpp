/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s, 0, 0, ip, res);
        return res;
    }
private:
    void dfs(string s, int start, int step, string ip, vector<string>& res) {
        if (start == s.size() && step == 4) {
            ip.erase(ip.end() - 1);
            res.push_back(ip);
            return;
        }
        if (s.size() - start > (4 - step) * 3 ||
            s.size() - start < (4 - step)) {
            return;
        }
        int num = 0;
        for (int i = start; i < start + 3; ++i) {
            num = num * 10 + s[i] - '0';
            if (num <= 255) {
                ip += s[i];
                dfs(s, i + 1, step + 1, ip + '.', res);
            }
            if (num == 0) {
                break;
            }
        }
    }
};

int main()
{
    string s = "25525511135";
    Solution sol;
    vector<string> res = sol.restoreIpAddresses(s);
    for (const auto& level : res) {
        cout << level << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end