/*
Date: May 31, 2026
Platform: HackerRank (https://www.hackerrank.com/challenges/time-conversion)
-----------------------------------------------------------
Problem Statement:
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note:
- 12:00:00AM becomes 00:00:00
- 12:00:00PM remains 12:00:00
-----------------------------------------------------------
Approach:
Extract the hour, minutes-seconds part, and AM/PM indicator from the string.
If the time is AM and the hour is not 12, or if the time is PM and the hour is already 12,
the first 8 characters form the answer directly.
Otherwise, convert the hour to 24-hour format using (hour + 12) % 24,
format it as a two-digit string, and append the remaining time portion.
-----------------------------------------------------------
Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string timeConversion(string s) {
        string ind = s.substr(8);
        string hr = s.substr(0, 2);
        string rest = s.substr(2, 6);

        int h = stoi(hr);

        if((ind == "AM" && h != 12) || (ind == "PM" && h == 12)){
            return s.substr(0, 8);
        }

        h = (h + 12) % 24;

        hr = (h >= 10 ? to_string(h) : "0" + to_string(h));

        return hr + rest;
    }
};

int main() {
    string time;

    cout << "Enter time in HH:MM:SSAM/PM format:" << endl;
    cin >> time;

    Solution s;

    cout << "\n24-Hour Format: " << s.timeConversion(time) << endl;

    return 0;
}