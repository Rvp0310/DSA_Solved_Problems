/* 
Date: February 13, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/maximum-of-minimum-for-every-window-size3453)
-----------------------------------------------------------
Problem Statement:
You are given an integer array arr[], the task is to find the maximum of minimum values for every window size k where 1≤ k ≤ arr.size().

For each window size k, consider all contiguous subarrays of length k, determine the minimum element in each subarray, and then take the maximum among all these minimums.

Return the results as an array, where the element at index i represents the answer for window size i+1.
-----------------------------------------------------------
Approach:
Instead of checking all subarrays for every window size, the solution determines for each element arr[i] the largest window in which it can act as the minimum. A monotonic increasing stack st is used to find the previous and next smaller elements for every index.
When an element at index top is popped from the stack, the current index i becomes its next smaller element, and the new top of the stack becomes its previous smaller element. Using these two boundaries, the window size wndSize = right - left - 1 is calculated. This represents the maximum window length where arr[top] remains the minimum. The value arr[top] is then used to update len[wndSize], which stores the maximum minimum value for that window size.
After processing all elements, the remaining stack elements are handled similarly by assuming their right boundary is n.
The array res is then built from len, where res[i] corresponds to window size i + 1. Since the maximum of minimum values must be non-increasing as window size increases, a backward pass ensures res[i] = max(res[i], res[i + 1]) to maintain correctness.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n), len(n + 1, 0);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                int top = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                int wndSize = right - left - 1;
                len[wndSize] = max(len[wndSize], arr[top]);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int wndSize = n - left - 1;
            len[wndSize] = max(len[wndSize], arr[top]); 
        }
        
        for(int i = 1; i <= n; i++){
            res[i - 1] = len[i];
        }
        
        for(int i = n - 2; i >= 0; i--){
            res[i] = max(res[i], res[i + 1]);
        }
        
        return res;
    }
};

int main() {
    Solution obj;
    string input;
    vector<int> arr;

    cout << "Enter array elements(space separated):" << endl;
    getline(cin, input);

    stringstream ss(input);
    int el;
    
    while(ss >> el){
        arr.push_back(el);
    }

    vector<int> res = obj.maxOfMins(arr);

    cout << "Result: " << endl;
    for(int el: res){
        cout << el << "\t";
    }

    return 0;
}