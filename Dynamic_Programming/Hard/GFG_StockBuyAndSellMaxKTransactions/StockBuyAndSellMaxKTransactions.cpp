/* 
Date: March 21, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/maximum-profit4657)
-----------------------------------------------------------
Problem Statement:
Given an array prices[], where prices[i] represents the price of a stock on the i-th day, and an integer k representing the maximum number of transactions allowed, find the maximum profit that can be earned by performing at most k transactions.

Note: A transaction consists of buying and subsequently selling a stock and new transaction can start only when the previous transaction has been completed.
-----------------------------------------------------------
Approach:
For the k transactions version, the code treats each day as a choice between acting or skipping using two states: buy ([1]) and sell ([0]). When in buy state, curr[j][1] = max(-prices[i] + next[j][0], next[j][1]) means either buy today and move to sell state or skip; when in sell state, curr[j][0] = max(prices[i] + next[j-1][1], next[j][0]) means either sell today (completing one transaction) or skip. The loop runs backwards so next always holds future profit, and finally next[k][1] gives the best starting profit.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        
        vector<vector<int>> curr(k + 1, vector<int> (2)), next(k + 1, vector<int> (2, 0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j <= k; j++){
                curr[j][1] = max(-prices[i] + next[j][0], next[j][1]);
                
                curr[j][0] = max(prices[i] + next[j - 1][1], next[j][0]);
            }
            
            next = curr;
        }
        
        return next[k][1];
    }
};

int main(){
    string s;
    cout << "Enter elements of array (space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> nums;

    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Enter the no.of transactions allowed:" << endl;
    cin >> num;

    Solution sol;
    cout << "Max Profit Obtained For given is: " << sol.maxProfit(nums, num) << endl;

    return 0;
}