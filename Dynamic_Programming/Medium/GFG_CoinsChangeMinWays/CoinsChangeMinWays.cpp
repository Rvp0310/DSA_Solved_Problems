/* 
Date: March 15, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/number-of-coins1824)
-----------------------------------------------------------
Problem Statement:
You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.

Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.
-----------------------------------------------------------
Approach:
This directly checks whether any subset can form the given target sum. Use DP where each state represents whether a sum is possible. Start with sum 0 as always possible, then for each element update the DP by either taking it (reduce sum) or not taking it. If the target sum is marked achievable at the end, return true.
-----------------------------------------------------------
Time Complexity: O(n * sum)
Space Complexity: O(sum)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <climits>

using namespace std;

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j <= sum; j++){
                int take = INT_MAX, noTake = INT_MAX;
                
                if(j - coins[i] >= 0 && coins[i] > 0 && dp[j - coins[i]] != INT_MAX){
                    take = (dp[j - coins[i]] + 1);
                }
                
                if(i + 1 < n){
                    noTake = dp[j];
                }
                
                dp[j] = min(take, noTake);
            }
        }
        
        return (dp[sum] == INT_MAX ? -1 : dp[sum]);
    }
};

int main(){
    string s;
    cout << "Enter coins denomination (space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> c;

    while(ss >> num){
        c.push_back(num);
    }

    cout << "Enter Sum:" << endl;
    cin >> num;

    Solution sol;
    cout << "Min Ways For Change Possible: " << sol.minCoins(c, num) << endl;
    return 0;
}