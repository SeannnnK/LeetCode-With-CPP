/*
 * @lc app=leetcode id=1360 lang=cpp
 *
 * [1360] Number of Days Between Two Dates
 */

// @lc code=start
// Unknown
// Write a program to count the number of days between two dates.  The two dates are given as
// strings, their format is YYYY-MM-DD as shown in the examples.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2)
    {
        return abs(date_to_int(date2) - date_to_int(date1));
    }

private:
    bool is_leap_year(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int date_to_int(string s_date)
    {
        int Y = stoi(s_date.substr(0, 4));
        int M = stoi(s_date.substr(5, 2));
        int D = stoi(s_date.substr(8, 2));

        int date = 0;
        for (int y = 1971; y < Y; ++y) {
            date += is_leap_year(y) ? 366 : 365;
        }
        for (int m = 1; m < M; ++m) {
            date += days_in_month(m, Y);
        }
        date += D;

        return date;
    }

    int days_in_month(int m, int y)
    {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            return 31;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        } else {
            return is_leap_year(y) ? 29 : 28;
        }
    }
};

class Solution2 {
public:
    int daysBetweenDates(string date1, string date2)
    {
        date d1 = date_to_struct(date1);
        date d2 = date_to_struct(date2);
        return get_diff(d1, d2);
    }

private:
    vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    struct date
    {
        int y;
        int m;
        int d;
    };

    date date_to_struct(string s_date)
    {
        date d;
        d.y = stoi(s_date.substr(0, 4));
        d.m = stoi(s_date.substr(5, 2));
        d.d = stoi(s_date.substr(8, 2));
        return d;
    }

    int count_leap_years(date d)
    {
        int year = d.y;
        if (d.m <= 2) {
            --year;
        }
        return year / 4 - year / 100 + year / 400;
    }

    int get_diff(date d1, date d2)
    {
        int n1 = d1.y * 365 + d1.d;
        for (int i = 0; i < d1.m - 1; ++i) {
            n1 += months[i];
        }
        n1 += count_leap_years(d1);

        int n2 = d2.y * 365 + d2.d;
        for (int i = 0; i < d2.m - 1; ++i) {
            n2 += months[i];
        }
        n2 += count_leap_years(d2);

        return abs(n2 - n1);
    }
};

int main()
{
    Solution sol;
    Solution2 sol2;
    string date1 = "2020-01-15", date2 = "2019-12-31";
    cout << sol.daysBetweenDates(date1, date2) << endl;
    cout << sol2.daysBetweenDates(date1, date2) << endl;
    return 0;
}
// @lc code=end
