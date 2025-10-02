/* 
Date: January 22, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/non-overlapping-intervals)
-----------------------------------------------------------
Problem Statement:
Given a 2D array intervals[][], where intervals[i] = [starti, endi]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Note: Two intervals are considered non-overlapping if the end time of one interval is less than or equal to the start time of the next interval.
-----------------------------------------------------------
Approach:
First sort all intervals based on their end times in ascending order, which allows for a greedy approach that prioritizes keeping intervals that finish earlier. Starting with the first interval, compare each subsequent interval to the last included one. If the current interval starts before the last one ends, it means there's an overlap, so it's counted for removal. Otherwise, the current interval becomes the new last reference for comparison.
-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        vector<int> last = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(last[1] > intervals[i][0]){
                count++;
            }else{
                last = intervals[i];
            }
        }
        return count;
    }
};

int main() {
    string line;
    cout << "Enter intervals (each as 'start end', separated by newlines). Enter an empty line to stop:\n";
    vector<vector<int>> intervals;
    while (true) {
        getline(cin, line);
        if (line.empty()) break;

        stringstream ss(line);
        int start, end;
        if (ss >> start >> end) {
            intervals.push_back({start, end});
        } else {
            cout << "Invalid input. Please enter two integers per line.\n";
        }
    }
    if (intervals.empty()) {
        cout << "No intervals provided. Exiting.\n";
        return 1;
    }

    Solution s;
    cout << "\nMinimum number of intervals to remove: " << s.minRemoval(intervals) << endl;
    return 0;
}
