/* 
Date: February 7, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/stock-span-problem-1587115621)
-----------------------------------------------------------
Problem Statement:
The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.
You are given an array arr[] representing daily stock prices, the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.
-----------------------------------------------------------
Approach:
Use a stack to store indices of days in decreasing order of stock prices.
The stack helps in finding the nearest previous day with a higher stock price.

For each day i:
- Pop indices from the stack while the stock price at those indices is
  less than or equal to the current day's price.
- If the stack becomes empty, it means no previous higher price exists,
  so the span is i + 1.
- If the stack is not empty, the span is the difference between the
  current index and the index on top of the stack.
- Push the current day's index onto the stack.

Each index is pushed and popped at most once, ensuring efficiency.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && (arr[st.top()] <= arr[i])){
                st.pop();
            }
            
            if(st.empty()){
                res[i] = i + 1;
            } else {
                res[i] = i - st.top();
            }
            
            st.push(i);
        }
        
        return res;
    }
};

int main() {
    Solution obj;
    string input;
    vector<int> arr;
    
    cout << "Enter stock prices (space separated):" << endl;
    getline(cin, input);
    
    stringstream ss(input);
    int num;
    
    while(ss >> num){
        arr.push_back(num);
    }
    
    vector<int> result = obj.calculateSpan(arr);
    
    cout << "Stock Span Array:" << endl;
    for(int x : result){
        cout << x << " ";
    }
    
    return 0;
}