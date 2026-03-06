/* 
Date: March 5, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/edit-distance3702)
-----------------------------------------------------------
Problem Statement:
Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
-----------------------------------------------------------
Approach:
Instead of storing the entire m × n DP table, we optimize space by keeping only a single row (curr) and a variable prev to represent the diagonal value from the previous iteration. Initially, curr[j] represents the cost of converting an empty string to the first j characters of s2 (i.e., j insertions). Then for each character i in s1, we update the row while storing the previous diagonal value. If s1[i-1] == s2[j-1], no operation is needed so we take the diagonal value (prev). Otherwise, we take 1 + min(insert, replace, delete) which correspond to curr[j-1], prev, and curr[j] respectively. After processing all characters, curr[n] contains the minimum edit distance between the two strings.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int editDistance(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();
        
        int prev = 0;
        vector<int> curr(n + 1, 0);
        
        for(int j = 1; j <= n; j++){
            curr[j] = j;
        }
        
        for(int i = 1; i <= m; i++){
            prev = curr[0];
            curr[0] = i;
            
            for(int j = 1; j <= n; j++){
                int temp = curr[j];
                
                if(s1[i - 1] == s2[j - 1]){
                    curr[j] = prev;
                } else {
                    curr[j] = 1 + min({curr[j - 1], prev, curr[j]});
                }
                
                prev = temp;
            }
        }
        
        return curr[n];
    }
};

int main(){
    string s1, s2;
    cout << "Enter first string:" << endl;
    getline(cin, s1);

    cout << "Enter second string:" << endl;
    getline(cin, s2);

    Solution sol;
    cout << "No.of Eddits Required to covert: " << sol.editDistance(s1, s2) << endl;
    return 0;
}