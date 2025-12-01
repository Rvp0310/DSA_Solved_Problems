/* 
Date: January 24, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/overlapping-intervals--170633)
-----------------------------------------------------------
Problem Statement:
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.
-----------------------------------------------------------
Approach:
The list of intervals is first sorted based on their starting points. Once sorted, each interval is compared with the last one in the result. If the current interval starts before or when the last one ends, it means they overlap. In that case, their end points are merged by taking the maximum of both. If there’s no overlap, the current interval is simply added to the result list as a new entry. This ensures that all overlapping intervals are combined into the smallest possible number of non-overlapping intervals.
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
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        for(int i = 1; i < n; i++){
            vector<int>& last = ans.back();
            vector<int>& curr = arr[i];
            if(curr[0] <= last[1]){
                last[1] = max(curr[1], last[1]);
            }
            else{
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

int main() {
    string line;
    cout << "Enter intervals (each as 'start end', separated by newlines). Enter an empty line to stop:" << endl;
    
    vector<vector<int>> intervals;
    
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        
        stringstream ss(line);
        int start, end;
        if (ss >> start >> end) {
            intervals.push_back({start, end});
        } else {
            cout << "Invalid input. Please enter two integers per line." << endl;
        }
    }

    Solution s;
    vector<vector<int>> merged = s.mergeOverlap(intervals);
    
    cout << "\nMerged Intervals:" << endl;
    for (const auto& interval : merged) {
        cout << interval[0] << " " << interval[1] << endl;
    }
    return 0;
}

