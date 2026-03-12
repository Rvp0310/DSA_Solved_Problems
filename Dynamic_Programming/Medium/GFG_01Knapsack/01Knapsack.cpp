/* 
Date: March 12, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/0-1-knapsack-problem0945)
-----------------------------------------------------------
Problem Statement:
Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, and an integer W representing the maximum capacity of the knapsack (the total weight it can hold).

The task is to put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.

Note: You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.
-----------------------------------------------------------
Approach:
For a given capacity j, when a new item is considered there are two possibilities: either we keep the previous profit already stored for that capacity (which means the current item is not taken), or we include the current item if its weight fits within the capacity. If we include it, the new profit becomes the value of the current item plus the optimal profit already computed for the remaining capacity j − wt[i]. Therefore, the profit for capacity j is updated as the maximum of the previous profit at that capacity and the profit obtained by adding the current item to the best solution for the reduced capacity. This process is repeated for all items while iterating the capacities in reverse so that each item is considered only once.
-----------------------------------------------------------
Time Complexity: O(n * W)
Space Complexity: O(W)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<int> dp(W + 1, 0); // first row where no items are considered
        
        for(int i = 1; i <= wt.size(); i++){
            for(int j = W; j >= wt[i - 1]; j--){
                dp[j] = max(dp[j], (dp[j - wt[i - 1]] + val[i - 1]));
            }
        }
        
        return dp[W];
    }
};

int main(){
    string s;
    cout << "Enter the weight of items (space separated):" << endl;
    getline(cin, s);
    stringstream ss1(s);
    int num;
    vector<int> w;

    while(ss1 >> num){
        w.push_back(num);
    }

    cout << "Enter the weight of items (space separated):" << endl;
    getline(cin, s);
    stringstream ss2(s);
    vector<int> p;

    while(ss2 >> num){
        p.push_back(num);
    }

    cout << "Enter Bag Capacity:" << endl;
    cin >> num;

    Solution sol;
    cout << "Optimal Profit: " << sol.knapsack(num, p, w) << endl;
    return 0;
}