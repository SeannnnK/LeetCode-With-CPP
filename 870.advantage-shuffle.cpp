/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
// Unknown
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B)
    {
        int n = A.size();
        vector<int> res(n, 0);
        int i = 0;
        using range = pair<int, int>;
        int low = 0, high = n - 1;

        if (n != B.size()) {
            return res;
        }
        auto compare = [](const range& a, const range& b) {
            return a.first < b.first;
        };
        priority_queue<range, vector<range>, decltype(compare)> q(compare);

        sort(A.begin(), A.end());

        for (int i = 0; i < n; ++i) {
            q.push(make_pair(B[i], i));
        }

        while (!q.empty()) {
            if (q.top().first < A[high]) {
                res[q.top().second] = A[high--];
            } else {
                res[q.top().second] = A[low++];
            }
            q.pop();
        }
        return res;
    }
};

int main()
{
    vector<int> A{2, 7, 11, 15}, B{1, 10, 4, 11};
    Solution sol;
    vector<int> res = sol.advantageCount(A, B);
    for (const auto& n : res) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end
