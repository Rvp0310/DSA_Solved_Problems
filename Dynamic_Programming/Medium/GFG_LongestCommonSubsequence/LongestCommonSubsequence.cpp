/* 
Date: February 15, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-common-subsequence-1587115620)
-----------------------------------------------------------
Problem Statement:
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".
-----------------------------------------------------------
Approach:

-----------------------------------------------------------
Time Complexity: O(nlogn + n*m²)
Auxiliary Space: O(n * m)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};

int main(){
    string s1, s2;
    cout << "Enter first string:" << endl;
    getline(cin, s1);

    cout << "Enter second string:" << endl;
    getline(cin, s2);

    Solution sol;
    cout << "Longest common Subsequence length in given two strings: " << sol.lcs(s1, s2)<< endl;
    return 0;
}