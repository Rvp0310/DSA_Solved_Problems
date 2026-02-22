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
The optimized solution uses two 1D arrays, prev and curr, instead of a 2D DP table. Here, i represents the starting index of a substring and j represents the ending index. The value curr[j] stores the longest palindromic subsequence length for the substring from i to j.
The outer loop runs from right to left because each state depends on results of the next index (i + 1). For each i, curr[i] is set to 1 since a single character is always a palindrome.
For every j > i, if s[i] == s[j], the value becomes prev[j - 1] + 2. Otherwise, it becomes max(prev[j], curr[j - 1]). After processing one row, curr is assigned to prev for the next iteration.
The final answer is stored in the last index of the curr array.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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