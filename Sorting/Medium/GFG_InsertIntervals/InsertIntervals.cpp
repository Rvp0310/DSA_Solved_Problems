/* 
Date: January 22, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/insert-interval-1666733333)
-----------------------------------------------------------
Problem Statement:
Geek has an array of non-overlapping intervals intervals[][] where intervals[i] = [starti , endi] represent the start and the end of the i th event and intervals is sorted in ascending order by starti . He wants to add a new interval newInterval[] = [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.
Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
-----------------------------------------------------------
Approach:
First add all intervals that end before the new interval starts, as they clearly don't overlap. Then,merge all intervals that overlap with the new one by expanding the new interval’s start to the minimum start and its end to the maximum end among the overlapping intervals. Finally, add the rest of the intervals that begin after the merged interval ends.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> ans;
        
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

int main() {
    string line;
    cout << "Enter existing intervals (each as 'start end', separated by newlines). Enter an empty line to stop:\n";
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

    cout << "Enter the new interval to insert (as 'start end'):\n";
    vector<int> newInterval;
    getline(cin, line);
    stringstream ss(line);
    int start, end;
    if (ss >> start >> end) {
        newInterval = {start, end};
    } else {
        cout << "Invalid input for new interval.\n";
        return 1;
    }

    Solution s;
    vector<vector<int>> result = s.insertInterval(intervals, newInterval);
    cout << "\nIntervals after insertion:\n";
    for (const auto& interval : result) {
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}
