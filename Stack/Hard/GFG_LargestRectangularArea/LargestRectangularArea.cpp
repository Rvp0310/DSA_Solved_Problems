/* 
Date: February 8, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/maximum-rectangular-area-in-a-histogram-1587115620)
-----------------------------------------------------------
Problem Statement:
You are given a histogram represented by an array arr[ ], where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.

Your task is to find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.
-----------------------------------------------------------
Approach:
The histogram is traversed from left to right while maintaining a stack that stores indices of bars in increasing height order. Whenever the current bar is shorter than the bar at the top of the stack, indices are popped from the stack and the area is calculated using the popped bar as the smallest height. The width of the rectangle is determined by the current index and the new top of the stack. The maximum area is updated during this process. After completing the traversal, the remaining bars in the stack are processed similarly by assuming the histogram ends at the last index. The largest area obtained is returned as the result.
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
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        int res = 0;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int tp = st.top();
                st.pop();
                
                int width = st.empty()? i : (i - st.top() - 1);
                res = max(res, (arr[tp] * width));
            }
            
            st.push(i);
        }
        
        while (!st.empty()){
            int tp = st.top();
            st.pop();
            int width = st.empty()? n : (n - st.top() - 1);
            res = max(res, (arr[tp] * width));
        }
        
        return res;
    }
};

int main() {
    Solution obj;
    string input;
    vector<int> arr;
    
    cout << "Enter histogram heights (space separated):" << endl;
    getline(cin, input);
    
    stringstream ss(input);
    int num;
    
    while(ss >> num){
        arr.push_back(num);
    }
    
    int res = obj.getMaxArea(arr);
    cout << "Largest Area in Given Histogram: " << res << endl;
    
    return 0;
}