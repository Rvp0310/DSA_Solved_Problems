/* 
Date: February 15, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-palindromic-subsequence-1612327878)
-----------------------------------------------------------
Problem Statement:
Given a string s, return the length of the longest palindromic subsequence.
A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.
A palindromic sequence is a sequence that reads the same forward and backward.
-----------------------------------------------------------
Approach:

-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        int n = s.length();
        
        vector<int> curr(n), prev(n);
        
        for(int i = n - 1; i >= 0; i--){
            
            curr[i] = 1;
            
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    curr[j] = prev[j - 1] + 2;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            
            prev = curr;
        }
        
        return curr[n - 1];
    }
};

int main(){
    string s;
    cout << "Enter a string:" << endl;
    getline(cin, s);

    Solution sol;
    cout << "Longest palindromic Subsequence length in given string: " << sol.longestPalinSubseq(s) << endl;
    return 0;
}