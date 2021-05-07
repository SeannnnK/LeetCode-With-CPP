/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
// Unknown
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K)
    {
        return atMostK(A, K) - atMostK(A, K - 1);
    }

private:
    int atMostK(vector<int>& A, int K)
    {
        int i = 0, res = 0, n = A.size();
        unordered_map<int, int> m;

        for (int j = 0; j < n; ++j) {
            if (!m[A[j]]++) {
                --K;
            }
            while (K < 0) {
                if (!--m[A[i]]) {
                    ++K;
                }
                ++i;
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> A{1, 2, 1, 2, 3};
    cout << sol.subarraysWithKDistinct(A, 2) << endl;
    return 0;
}
// @lc code=end
