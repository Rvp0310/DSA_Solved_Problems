/* 
Date: March 25, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/total-decoding-messages1235)
-----------------------------------------------------------
Problem Statement:
A message containing letters A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are given a string digits. You have to determine the total number of ways that message can be decoded.
-----------------------------------------------------------
Approach:
The string is processed from left to right while keeping track of how many ways it can be decoded up to the previous positions using two variables. At each index, decoding can happen in two ways: either treat the current digit as a single character (valid only if it is not ‘0’), or combine it with the previous digit to form a two-digit number (valid only if it lies between 10 and 26). The variable prev1 stores the number of ways to decode up to the previous index, and prev2 stores the ways up to two steps back. For each position, current is calculated by adding prev1 if single-digit decoding is possible and adding prev2 if a valid two-digit decoding exists. Then the variables are shifted forward (prev2 = prev1, prev1 = current) to continue the process. This effectively builds the answer in a rolling manner, similar to Fibonacci, where each state depends only on the last two states.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.size(), prev1 = 1, prev2 = 0;
        
        if(n == 0 || digits[0] == '0'){
            return 0;
        }
        
        for(int i = 1; i <= n; i++){
            int current = 0;
            
            if(digits[i - 1] != '0'){
                current += prev1;
            }
            
            if(i > 1){
                int num = ((digits[i - 2] - '0') * 10) + (digits[i - 1] - '0');
                
                if(num <= 26 && num >= 10){
                    current += prev2;
                }
            }
            
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};

int main(){
    string s;
    cout << "Enter the string of numbers:" << endl;
    getline(cin, s);

    Solution sol;
    cout << "Ways to decode the string: " << sol.countWays(s) << endl;

    return 0;
}