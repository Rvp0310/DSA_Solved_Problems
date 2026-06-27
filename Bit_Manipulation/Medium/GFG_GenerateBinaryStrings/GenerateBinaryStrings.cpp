/* 
Date: June 27, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1?page=2&category=Bit%20Magic&sortBy=submissions)
-----------------------------------------------------------
Problem Statement:
Given an integer n. You need to generate all the binary strings of n characters representing bits.

Note: Return the strings in  ascending order.
-----------------------------------------------------------
Approach:
Generate all numbers from 0 to 2ⁿ−1. For each number, check every bit from left to right and build the corresponding binary string. Store each generated string in the result.
-----------------------------------------------------------
Time Complexity: O((2 ^ n) - 1)
Space Complexity: O((2 ^ n) - 1)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<string> binstr(int n) {
        vector<string> res;
        
        for(int i = 0; i < (1 << n); i++){
            string s;
            for(int j = n - 1; j >= 0; j--){
                s += ((i >> j) & 1) ? '1' : '0';
            }
            
            res.push_back(s);
        }
        
        return res;
    }
};

int main(){
    int n;
    cout << "Enter a number:" << endl;
    cin >> n;

    Solution s;
    vector<string> result = s.binstr(n);

    cout << "Binary strings:" << endl;
    for(string b: result){
        cout << b << endl;
    }

    return 0;
}