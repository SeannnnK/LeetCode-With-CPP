// Unknown
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> hash;
        for (const auto& num : nums) {
            ++hash[num];
        }
        for (const auto& p : hash) {
            if (hash.count(p.first + 1)) {
                res = max(res, hash[p.first] + hash[p.first + 1]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 3, 2, 2, 5, 2, 3, 7};
    cout << sol.findLHS(nums) << endl;
    return 0;
}