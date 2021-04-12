/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
// adobe | airbnb | amazon | apple | bloomberg | dropbox | facebook | linkedin | microsoft | uber | yahoo | yelp
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int key = target - num;
            auto pos = hash.find(key);
            if (pos == hash.end()) {
                hash[num] = i;
            } else {
                res.push_back(i);
                res.push_back(pos->second);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{2, 7, 11, 15};
    Solution sol;
    vector<int> res = sol.twoSum(nums, 9);
    for (const auto& num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end