/* 
Date: December 22, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/buy-stock-2)
-----------------------------------------------------------
Problem Statement:
Given an array prices[] of length n, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.
Note: Stock must be bought before being sold.
-----------------------------------------------------------
Approach:
I started by setting the first price as the minimum, then looped through the array checking the profit if I sold on each day. If that profit was higher than what I had before, I updated it — and also kept updating the minimum price whenever I found a lower one.
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
        int minprice = prices[0], maxprofit = 0, n = prices.size();
        for(int i = 1; i < n; i++)
        {
            int profit=prices[i]-minprice;
            maxprofit=max(maxprofit,profit);
            minprice=min(prices[i],minprice);
        }
        return maxprofit;
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