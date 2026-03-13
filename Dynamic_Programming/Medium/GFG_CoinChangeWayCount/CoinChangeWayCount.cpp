/* 
Date: March 13, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/coin-change2448)
-----------------------------------------------------------
Problem Statement:
Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
Answers are guaranteed to fit into a 32-bit integer. 
-----------------------------------------------------------
Approach:
Stored in dp[j] the number of ways to form the sum j. Initially dp[0] = 1 because there is exactly one way to form sum 0 (choosing no coins). Then for each coin denomination, update the possible sums starting from that coin value up to the target sum. For a given sum j, if the current coin is used, the remaining sum becomes j − coin, and the number of ways to form that remaining sum has already been calculated. Therefore add dp[j - coin] to dp[j], which effectively counts all combinations where the current coin contributes to forming the sum. By repeating this for every coin and every possible sum, dp[sum] finally stores the total number of combinations to form the required sum.
-----------------------------------------------------------
Time Complexity: O(n * sum)
Space Complexity: O(sum)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        
        vector<int> dp(sum + 1);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= sum; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        
        return dp[sum];
    }
};

int main(){
    string s;
    cout << "Enter the weight of items (space separated):" << endl;
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
    cout << "No.of Ways For Change: " << sol.count(c, num) << endl;
    return 0;
}