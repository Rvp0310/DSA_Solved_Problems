/* 
Date: May 22, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/boolean-parenthesization5610)
-----------------------------------------------------------
Problem Statement:
You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.
-----------------------------------------------------------
Approach:
Use dynamic programming to store the number of ways each substring can evaluate to true or false. The 3D DP array dp[i][j][0/1] represents the number of ways the expression from index i to j evaluates to false or true. Base cases are single characters: 'T' contributes to true count and 'F' contributes to false count. For every larger substring, try every operator position k as the partition point, divide the expression into left and right parts, and combine their true/false counts according to the operator (&, |, ^). All valid combinations that evaluate to true are added to dp[i][j][1], and the remaining combinations are added to dp[i][j][0]. Finally, dp[0][n-1][1] gives the total number of ways the full expression can evaluate to true.
-----------------------------------------------------------
Time Complexity: O(n ^ 3)
Space Complexity: O(n ^ 2)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
  
  bool evaluate(int op1, int op2, char op) {
      if (op == '&') {
          return op1 & op2;
      }
      
      if (op == '|') {
          return op1 | op2;
      }
      
      return op1 ^ op2;
  }
  
    int countWays(string &s) {
        int n = s.length();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, 0)));
        
        for(int i = 0; i < n; i += 2){
            dp[i][i][0] = (s[i] == 'F');
            dp[i][i][1] = (s[i] == 'T');
        }
        
        for(int len = 2; len < n; len += 2){
            for(int i = 0; i < n - len; i += 2){
                int j = i + len;
                
                dp[i][j][0] = dp[i][j][1] = 0;
                
                for(int k = i + 1; k < j; k += 2){
                    char op = s[k];
                    int leftTrue = dp[i][k - 1][1], leftFalse = dp[i][k - 1][0], rightTrue = dp[k + 1][j][1], rightFalse = dp[k + 1][j][0];
                    
                    if(evaluate(1, 1, op)){
                        dp[i][j][1] += leftTrue * rightTrue;    
                    }
                    if(evaluate(1, 0, op)){
                        dp[i][j][1] += leftTrue * rightFalse;    
                    }
                    if(evaluate(0, 1, op)){
                        dp[i][j][1] += leftFalse * rightTrue;    
                    }
                    if(evaluate(0, 0, op)){
                        dp[i][j][1] += leftFalse * rightFalse;    
                    }
                    
                    if(!evaluate(1, 1, op)){
                        dp[i][j][0] += leftTrue * rightTrue;    
                    }
                    if(!evaluate(1, 0, op)){
                        dp[i][j][0] += leftTrue * rightFalse;    
                    }
                    if(!evaluate(0, 1, op)){
                        dp[i][j][0] += leftFalse * rightTrue;    
                    }
                    if(!evaluate(0, 0, op)){
                        dp[i][j][0] += leftFalse * rightFalse;    
                    }
                }
            }
        }
        
        return dp[0][n - 1][1];
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a logical expression (use operations &, | and ^ only with T and F operands): ";
    getline(cin, input);

    cout << "No.of ways to parenthesize: " << sol.countWays(input);

    return 0;
}