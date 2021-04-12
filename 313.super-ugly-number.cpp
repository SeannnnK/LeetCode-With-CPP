/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
// google
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> q(
            compare);

        for (int i = 0; i < primes.size(); ++i) {
            q.push({primes[i], primes[i], 0});
        }

        vector<int> res(n, 0);
        int i = 1;
        res[0] = 1;

        while (i < n) {
            vector<int> tmp = q.top();
            int num = tmp[0], prime = tmp[1], index = tmp[2];

            if (res[i - 1] != num) {
                res[i] = num;
                ++i;
            }
            q.pop();
            q.push({prime * res[index + 1], prime, index + 1});
        }
        return res[n - 1];
    }
};

int main()
{
    vector<int> primes{2, 7, 13, 19};
    Solution sol;
    cout << sol.nthSuperUglyNumber(12, primes) << endl;
    return 0;
}
// @lc code=end
