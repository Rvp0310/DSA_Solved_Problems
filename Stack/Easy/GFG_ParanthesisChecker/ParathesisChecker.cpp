/* 
Date: December 28, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/parenthesis-checker2744)
-----------------------------------------------------------
Problem Statement:
Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']'. Determine whether the Expression is balanced or not.
An expression is balanced if:

Each opening bracket has a corresponding closing bracket of the same type.
Opening brackets must be closed in the correct order.
-----------------------------------------------------------
Approach:
Uses a stack to push opening brackets, pops and matches on every closing bracket, fails on mismatch or underflow, and finally checks the stack is empty for a perfectly balanced string.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool isBalanced(string& s) {
        int n = s.length();
        vector<char> st;
        for(int i = 0; i < n; i++){
            if((s[i] == '(') || (s[i] == '[') || (s[i] == '{')){
                st.push_back(s[i]);
            } 
            else {
                if(st.empty()){
                    return false;
                } else {
                    char rear = st.back();
                    st.pop_back();
                    if(((s[i] == ')') && (rear != '(')) 
                        || ((s[i] == ']') && (rear != '[')) 
                        || ((s[i] == '}') && (rear != '{'))){
                        return false;
                    }
                }
            }
        }
        
        return st.empty();
    }
};

int main(){
    string input;
    cout << "Enter sequence of paranthesis (), [], {}:" << endl;
    getline(cin, input);
    Solution s;
    if(s.isBalanced(input)){
        cout << "Paranthesis are balanced." << endl;
    } else {
        cout << "Paranthesis are not balanced." << endl;
    }
    return 0;
}