/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
// Unknown
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> s;
        vector<int> res(n);
        for (int i = 0; i < T.size(); ++i) {
            while (!s.empty()) { 
                int index = s.top();
                if (T[i] <= T[index]) {
                    break;
                }
                res[index] = i - index;
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

int main()
{
    vector<int> T{73, 74, 75, 71, 69, 72, 76, 73};
    Solution sol;
    vector<int> res = sol.dailyTemperatures(T);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end