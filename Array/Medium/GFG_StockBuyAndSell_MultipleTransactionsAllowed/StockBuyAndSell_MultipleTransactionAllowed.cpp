/* 
Date: December 22, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/stock-buy-and-sell2615)
-----------------------------------------------------------
Problem Statement:
The cost of stock on each day is given in an array price[]. Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day. Find the maximum profit that you can get.
Note: A stock can only be sold if it has been bought previously and multiple stocks cannot be held on any given day.
-----------------------------------------------------------
Approach:
Instead of finding the exact pair (lowest buy, highest sell) for each upward trend, simply collect every local increase — i.e., if prices[i] > prices[i-1], and add the difference to total profit. The idea is mathematically sound and logically equivalent to timing perfect buy/sell points within each upward slope.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n=prices.size();
        int profit=0;
        for(int i = 1; i < n; i++){
           if(prices[i] > prices[i - 1])
           {
               profit += (prices[i] - prices[i - 1]);
           }
        }
        return profit;
    }
};

int main(){
    string input;
    cout << "Enter the stock prices for next few days:" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> stocks;
    int num;

    while(ss >> num){
        stocks.push_back(num);
    }

    cout << "Stock prices for next few days:" <<endl;
    for(int i = 0; i < stocks.size(); i++){
        cout << stocks[i] << "\t";
    }

    Solution s;
    cout << "\nHighest profit that can be attained is " << s.maximumProfit(stocks) << endl;

    return 0;
}