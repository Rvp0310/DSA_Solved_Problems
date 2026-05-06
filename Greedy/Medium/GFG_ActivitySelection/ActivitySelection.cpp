/* 
Date: May 6, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/activity-selection-1587115620)
-----------------------------------------------------------
Problem Statement:
You are given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.
-----------------------------------------------------------
Approach:
Pair each activity’s start and finish time, and process them in increasing order of finish time (using sorting or a min-heap). Always pick the activity that finishes earliest because it leaves maximum room for the remaining activities. Keep track of the last selected activity’s finish time. For each next activity, if its start time is greater than the last finish time, select it and update the finish time. Continue this process to greedily select the maximum number of non-overlapping activities.
-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int ans = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < start.size(); i++){
            pq.push({finish[i], start[i]});
        }
        
        int fshTime = -1;
        
        while(!pq.empty()){
            pair<int, int> activity = pq.top();
            pq.pop();
            
            if(activity.second > fshTime){
                ans++;
                fshTime = activity.first;
            }
        }
        
        return ans;
    }
};

int main(){
    string input;
    cout << "Enter the start time of activities:" << endl;
    getline(cin, input);

    stringstream s1(input);
    vector<int> st;
    int num;

    while(s1 >> num){
        st.push_back(num);
    }

    cout << "Enter the finish time of activities in same order as above:" << endl;
    getline(cin, input);

    stringstream s2(input);
    vector<int> fs;

    while(s2 >> num){
        fs.push_back(num);
    }

    cout << "Activity Start - Finish Time:" <<endl;
    for(int i = 0; i < st.size(); i++){
        cout << st[i] << "\t" << fs[i] << endl;
    }

    Solution s;
    cout << "\nMax no.of activites that can be completed " << s.activitySelection(st, fs) << endl;

    return 0;

}
