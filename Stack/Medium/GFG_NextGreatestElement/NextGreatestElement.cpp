/* 
Date: February 7, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/next-larger-element-1587115620)
-----------------------------------------------------------
Problem Statement:
You are given an array arr[] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.
-----------------------------------------------------------
Approach:
Traverse the array from right to left and use a stack to keep track of elements
that are greater than the current element.
For each element:
- Pop elements from the stack while they are less than or equal to the current element.
- If the stack is not empty after popping, the top of the stack is the next greater element.
- If the stack is empty, the next greater element is default -1.
- Push the current element onto the stack.

This ensures that each element is pushed and popped at most once.
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
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> res(n, -1);
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                res[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        return res;
    }
};

int main() {
    Solution obj;
    string input;
    vector<int> arr;
    
    cout << "Enter array elements (space separated):" << endl;
    getline(cin, input);
    
    stringstream ss(input);
    int num;
    
    while(ss >> num){
        arr.push_back(num);
    }
    
    vector<int> result = obj.nextLargerElement(arr);
    
    cout << "Next Greater Elements:" << endl;
    for(int x : result){
        cout << x << " ";
    }
    
    return 0;
}