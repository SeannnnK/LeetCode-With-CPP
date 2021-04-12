// [290]
// dropbox | uber

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        vector<int> patternMap(26, 0);
        unordered_map<string, int> strMap;
        // it's so easy to write like this to part the string
        istringstream iss(str);
        int i = 0, n = pattern.size();
        for (string token; iss >> token; ++i) {
            if (i == n || patternMap[pattern[i] - 'a'] != strMap[token]) {
                return false;
            }
            patternMap[pattern[i] - 'a'] = strMap[token] = i + 1;
        }
        return i == n;
    }
};

int main()
{
    Solution sol;
    cout << sol.wordPattern("abba", "dog cat cat dog") << endl;
    return 0;
}
