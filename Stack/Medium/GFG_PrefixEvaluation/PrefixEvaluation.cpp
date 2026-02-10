/* 
Date: February 10, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/evaluation-of-postfix-expression1735)
-----------------------------------------------------------
Problem Statement:
You are given an array of strings arr[] that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

Note: A postfix expression is of the form operand1 operand2 operator (e.g., "a b +"). 
And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.
It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.
-----------------------------------------------------------
Approach:
The postfix expression is evaluated using a stack because operands must be processed before operators. Scan the array from left to right. If the current element is a number (including negative values), it is converted to an integer and pushed onto the stack. If the element is an operator, the top two elements are popped from the stack, where the first popped value acts as the right operand and the second as the left operand. The operation is performed accordingly and the result is pushed back onto the stack. Special handling is applied for division to ensure floor division for negative values, as required by the problem. After processing all elements, the final result remains at the top of the stack and is returned.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

class Solution {
  public:
  
  int floor_Div(int a, int b){
    if(a * b < 0 && a % b != 0){
        return ((a/b) - 1);
    }    
    return a/b;
  }
  
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for(string c: arr){
            if(isdigit(c[0]) || (c.length() > 1 && c[0] == '-')){
                st.push(stoi(c));
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                if(c == "+"){
                    st.push(b + a);
                } else if (c == "-"){
                    st.push(b - a);
                } else if (c == "*"){
                    st.push(b * a);
                } else if (c == "/"){
                    st.push(floor_Div(b, a));
                } else if (c == "^"){
                    st.push(pow(b, a));
                }
                
            }
        }
        
        return st.top();
    }
};

int main() {
    Solution obj;
    string input;
    vector<string> arr;
    
    cout << "Enter postfix expression elements (space separated):" << endl;
    getline(cin, input);
    
    stringstream ss(input);
    string el;
    
    while(ss >> el){
        arr.push_back(el);
    }
    
    int result = obj.evaluatePostfix(arr);
    
    cout << "The Result Of Given Postfix Expression: " << result << endl;
    
    return 0;
}