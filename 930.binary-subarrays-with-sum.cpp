/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
// Unknown
// In an array A of 0s and 1s, how many non-empty subarrays have sum S?
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S)
    {
        return atMostK(A, S) - atMostK(A, S - 1);
    }

private:
    int atMostK(vector<int>& A, int S)
    {
        if (S < 0) {
            return 0;
        }
        int i = 0, n = A.size(), res = 0;
        for (int j = 0; j < n; ++j) {
            S -= A[j];
            while (S < 0) {
                S += A[i++];
            }
            res += j - i + 1;
        }
        return res;
    }

public:
    int numSubarraysWithSum2(vector<int>& A, int S)
    {
        unordered_map<int, int> m{{0, 1}};
        int p_sum = 0, res = 0;
        for (const auto & i : A) {
            p_sum += i;
            res += m[p_sum - S];
            ++m[p_sum];
        }
        return res;
    }
};

int main()
{
    vector<int> A{1, 0, 1, 0, 1};
    Solution sol;
    cout << sol.numSubarraysWithSum(A, 2) << endl;
    cout << sol.numSubarraysWithSum2(A, 2) << endl;
    return 0;
}
// @lc code=end
