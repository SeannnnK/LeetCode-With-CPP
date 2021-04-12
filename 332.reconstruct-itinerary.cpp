/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
// google

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> hash;
        if (tickets.empty()) {
            return res;
        }
        for (const auto& ticket : tickets) {
            hash[ticket[0]].insert(ticket[1]);
        }
        stack<string> s;
        s.push("JFK");
        while (!s.empty()) {
            string next = s.top();
            if (hash[next].empty()) {
                res.push_back(next);
                s.pop();
            } else {
                s.push(*hash[next].begin());
                hash[next].erase(hash[next].begin());
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> tickets{{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> res = sol.findItinerary(tickets);
    for (const auto& s : res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end