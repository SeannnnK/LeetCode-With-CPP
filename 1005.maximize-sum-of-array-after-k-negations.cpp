/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
#include <vector>
#include <numeric> // accumulate
#include <algorithm> // min_element
#include <iostream>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size() && A[i] < 0 && K > 0; ++i) {
            A[i] = -A[i];
            --K;
        }
        return accumulate(A.begin(), A.end(), 0) - (K % 2) * (*min_element(A.begin(), A.end()) * 2);
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<int> A{2,-3,-1,5,-4};
    cout << sol.largestSumAfterKNegations(A, 2) << endl;
    return 0;
}