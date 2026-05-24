/* 
Date: May 24, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/minimum-platforms-1587115620)
-----------------------------------------------------------
Problem Statement:
Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900).
-----------------------------------------------------------
Approach:
The arrival and departure times are treated like events on a timeline.
Whenever a train arrives, the platform count increases by 1, and whenever a train departs, the platform count decreases by 1.

A difference array is used to mark these changes:

+1 at arrival time
-1 just after departure time

Then a prefix sum is applied over the timeline to find how many trains are present at every moment.
The maximum number of trains present at the same time gives the minimum number of platforms required so that no train has to wait.

Tiny railway station energy. Count chaos. Find peak chaos. That peak is the answer.
-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        int maxDep = dep[0];
        
        for(int i = 1; i < n; i++){
            maxDep = max(maxDep, dep[i]);
        }
        
        vector<int> v(maxDep + 2, 0);
        
        for(int i = 0; i < n; i++){
            v[arr[i]]++;
            v[dep[i] + 1]--;
        }
        
        int count = 0, res = 0;
        for(int i = 0; i < maxDep + 1; i++){
            count += v[i];
            res = max(count, res);
        }
        
        return res;
    }
};

int main(){
    string input;
    cout << "Enter the arrival times of train:" << endl;
    getline(cin, input);

    stringstream s1(input);
    vector<int> a;
    int num;

    while(s1 >> num){
        a.push_back(num);
    }

    cout << "Enter the departure times of train:" << endl;
    getline(cin, input);

    stringstream s2(input);
    vector<int> d;

    while(s2 >> num){
        d.push_back(num);
    }

    cout << "Train Arrival - Departure Time:" <<endl;
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << "\t" << d[i] << endl;
    }

    Solution s;
    cout << "\nMin platform required " << s.minPlatform(a, d) << endl;

    return 0;

}
