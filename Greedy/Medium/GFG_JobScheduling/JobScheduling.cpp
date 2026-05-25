/* 
Date: May 25, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/job-sequencing-problem-1587115620)
-----------------------------------------------------------
Problem Statement:
You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
-----------------------------------------------------------
Approach:
Each job takes 1 unit of time, so the goal is to schedule the most profitable jobs before their deadlines. First, all jobs are stored as {deadline, profit} pairs and sorted according to deadlines. A min-heap is used to keep track of selected job profits. While traversing the sorted jobs, if the current number of selected jobs is less than the current job’s deadline, the job can be added directly. Otherwise, if the current job gives more profit than the minimum profit job already selected, the less profitable job is removed and replaced with the current one. This ensures that only the most profitable jobs are kept within the available deadlines. Finally, the heap size gives the maximum number of jobs completed, and the sum of heap elements gives the maximum profit.
-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        
        vector<int> ans = {0, 0};
        vector<pair<int, int>> jobs;
        
        for(int i = 0; i < n; i++){
            jobs.push_back({deadline[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n; i++){
            if(jobs[i].first > pq.size()){
                pq.push(jobs[i].second);
            }
            else if (!pq.empty() && pq.top() < jobs[i].second){
                pq.pop();
                pq.push(jobs[i].second);
            }
        }
        
        while(!pq.empty()){
            ans[1] += pq.top();
            pq.pop();
            ans[0]++;
        }
        
        return ans;
    }
};

int main(){
    string input;
    cout << "Enter the deadlines (space separated, enter when done):" << endl;
    getline(cin, input);

    stringstream s1(input);
    vector<int> d;
    int num;

    while(s1 >> num){
        d.push_back(num);
    }

    cout << "Enter the profits (space separated, enter when done):" << endl;
    getline(cin, input);

    stringstream s2(input);
    vector<int> p;

    while(s2 >> num){
        p.push_back(num);
    }

    cout << "Deadlines - Profits:" <<endl;
    for(int i = 0; i < d.size(); i++){
        cout << d[i] << "\t" << p[i] << endl;
    }

    Solution s;
    vector<int> result = s.jobSequencing(d, p);
    cout << "\nMax no.of jobs that can be completed " << result[0] << endl;
    cout << "\nProfit achieved: " << result[1] << endl;

    return 0;

}
