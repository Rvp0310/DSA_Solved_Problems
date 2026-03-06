/* 
Date: March 6, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/min-cost-climbing-stairs)
-----------------------------------------------------------
Problem Statement:
Given an array of integers cost[] where cost[i] is the cost of the ith step on a staircase. Once the cost is paid, you can either climb one or two steps. Return the minimum cost to reach the top of the floor.
Assume 0-based Indexing. You can either start from the step with index 0, or the step with index 1.
-----------------------------------------------------------
Approach:
To reach any stair i, the person must have come either from stair i−1 or stair i−2, since only 1 or 2 steps can be climbed at a time. Therefore, the minimum cost to reach stair i is the cost of that stair plus the minimum cost of reaching either of the previous two stairs, giving the recurrence dp[i] = cost[i] + min(dp[i−1], dp[i−2]). Since the person can start from index 0 or index 1, the first two states are initialized with their respective costs. Instead of storing the entire DP array, we observe that each step only depends on the previous two computed costs, so we keep two variables (prev1 and prev2) representing the minimum cost to reach the last two stairs and iteratively update them while traversing the array. Finally, reaching the top of the floor does not require paying a cost on a new stair, so the answer is the minimum of the costs required to reach the last two stairs, from which the top can be reached in one step.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1){
            return cost[0];
        } else if(n == 2){
            return min(cost[0], cost[1]);
        }
        
        int prev1 = cost[0], prev2 = cost[1];
        
        for(int i = 2; i < n; i++){
            int curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        
        return min(prev1, prev2);
    }
};

int main(){
    string s;
    cout << "Enter the cost of stair steps in order(space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> arr;

    while(ss >> num){
        arr.push_back(num);
    }

    Solution sol;
    cout << "Minimum cost to reach upstairs: " << sol.minCostClimbingStairs(arr) << endl;
    return 0;
}