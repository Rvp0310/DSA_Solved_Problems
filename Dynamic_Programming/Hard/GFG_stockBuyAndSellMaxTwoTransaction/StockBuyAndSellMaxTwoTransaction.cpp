/* 
Date: March 21, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/buy-and-sell-a-share-at-most-twice)
-----------------------------------------------------------
Problem Statement:
In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.

You are given an array prices[] representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).
-----------------------------------------------------------
Approach:
For the 2-transaction version, the process is tracked as four stages that happen in order: buy → sell → buy → sell. `firstBuy = max(firstBuy, -prices[i])` stores the lowest cost to buy the first stock, `firstSell = max(firstSell, firstBuy + prices[i])` stores the best profit after completing the first sell, `secondBuy = max(secondBuy, firstSell - prices[i])` uses that profit to buy again at the best effective cost, and `secondSell = max(secondSell, secondBuy + prices[i])` gives the final maximum profit after the second sell. Each step simply decides whether to perform that action on the current day or carry forward the best result so far, ensuring the transactions happen in sequence.
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
    int maxProfit(vector<int> &prices) {
        int n = prices.size(), firstBuy = INT_MIN, secondBuy = INT_MIN, firstSell = 0, secondSell = 0;
        
        for(int i = 0; i < n; i ++){
            firstBuy = max(firstBuy, -prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);
            secondBuy = max(secondBuy, firstSell - prices[i]);
            secondSell = max(secondSell, secondBuy + prices[i]);
        }
        
        return secondSell;
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

    Solution sol;
    cout << "Max Profit Obtained For given is: " << sol.maxProfit(nums) << endl;

    return 0;
}