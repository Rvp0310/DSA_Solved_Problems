/* 
Date: February 4, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/longest-valid-parentheses5657)
-----------------------------------------------------------
Problem Statement:
Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.
-----------------------------------------------------------
Approach:
Uses a stack to store indices of opening parentheses and a base index (-1). 
On encountering '(', its index is pushed. On encountering ')', an index is popped.
If the stack becomes empty, the current index is pushed as a new base. Otherwise, 
the length of the current valid substring is calculated using the difference 
between the current index and the stack top, and the maximum length is updated.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int maxLength(string& s) {
        stack<int> st;
        stack<char> ch;
        st.push(-1);
        int maxLen = 0;
        
        for(int i = 0; i < s.length(); i++){
           if(s[i] == '('){
               st.push(i);
           } else {
              st.pop();
              
              if(st.empty()){
                 st.push(i);
              } else {
                maxLen = max(maxLen, i - st.top());
              }
           }
        }
        
        return maxLen;
    }
};

int main() {
    Solution obj;
    string s;
    
    cout << "Enter a string of paranthesis:" << endl;
    cin >> s;
    
    cout <<"Maximum length Valid Substring: " << obj.maxLength(s) << endl;
    
    return 0;
}
