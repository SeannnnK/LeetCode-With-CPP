/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
// amazon | bloomberg | microsoft | uber

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string s)
    {
        int n = s.size(), i = 0;
        bool minus = false;
        int res = 0;
        if (n == 0) {
            return 0;
        }
        while (i < n) {
            while (s[i] == ' ') {
                ++i;
            }
            if (!isdigit(s[i])) {
                if (s[i] == '-') {
                    minus = true;
                } else if (s[i] != '+') {
                    return 0;
                }
                ++i;
            }

            // process the digit
            while (i < n) {
                if (!isdigit(s[i])) {
                    return minus ? -res : res;
                }
                if (res > ((INT_MAX - (s[i] - '0')) / 10)) {
                    if (minus) {
                        return INT_MIN;
                    } else {
                        return INT_MAX;
                    }
                }
                // notice the parathesis is must, or else it will overflow the integer
                res = 10 * res + (s[i] - '0');
                ++i;
            }
        }
        if (minus) {
            return -res;
        }
        return res;
    }
};

// @lc code=end
//
class Solution2 {
public:
    int myAtoi(string s)
    {
        if (s.empty()) {
            return 0;
        }
        int i = 0;
        int sign = 1;
        int res = 0;

        // parse the extra empty blanks
        while (s[i] == ' ' || s[i] == '\t') {
            ++i;
        }
        if (i == s.size()) {
            return 0;
        }

        // parse sign
        if (s[i] == '+') {
            sign = 1;
            ++i;
            if (!isdigit(s[i])) {
                return 0;
            }
        }
        if (s[i] == '-') {
            sign = -1;
            ++i;
            if (!isdigit(s[i])) {
                return 0;
            }
        }

        // compute integer
        for (; i < s.size() && isdigit(s[i]); ++i) {
            if (res > (numeric_limits<int>::max() - (s[i] - '0')) / 10) {
                return sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            res *= 10;
            res += s[i] - '0';
        }

        res *= sign;
        return res;
    }
};

int main()
{
    vector<string> v{"123", "  -12", "  -2147483649", "  +32jif", "fjai123", "+-jfai11"};
    Solution so;
    Solution2 so2;
    for (int i = 0; i < v.size(); ++i) {
        cout << so.myAtoi(v[i]) << endl;
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << so2.myAtoi(v[i]) << endl;
    }
    return 0;
}
