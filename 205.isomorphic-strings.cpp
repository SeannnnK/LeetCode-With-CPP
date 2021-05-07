/*
 * string s and t to check wheatehr they are isomorphic
 * [205]
 */
// linkedin
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class isTwoStringIsomorphic {
public:
    bool isIsoMorphic(string s, string t)
    {
        /*
         * attention! you need two hash map to check whether they are
         * isomorphic. bar->foo will be an example if you just use one
         * hash map. Another is you can use vector<int, int> to substitute
         * hash map.
         */
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> s2tMap;
        unordered_map<char, char> t2sMap;
        for (int i = 0; i < s.size(); ++i) {
            // count is used to check whether the element is exist in
            // the hash map.
            if (!s2tMap.count(s[i]) && !t2sMap.count(t[i])) {
                s2tMap[s[i]] = t[i];
                t2sMap[t[i]] = s[i];
            } else if (s2tMap[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};

/*
 * above is same with #290, I wrote as below:
 */

class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        vector<int> p2s(26, 0);
        unordered_map<string, int> s2p;

        istringstream iss(s);
        int i = 0, n = pattern.size();
        for (string token; iss >> token; ++i) {
            if (i == n || p2s[pattern[i] - 'a'] != s2p[token]) {
                return false;
            }
            p2s[pattern[i]] = s2p[token] = i + 1;
        }
        return i == n;
    }
};

int main()
{
    string s1 = "egg", s2 = "add";
    isTwoStringIsomorphic iTSI;
    cout << iTSI.isIsoMorphic(s1, s2) << endl;
    return 0;
}
