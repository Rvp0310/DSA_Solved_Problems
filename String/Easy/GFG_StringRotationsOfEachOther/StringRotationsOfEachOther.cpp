/* 
Date: January 7, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/check-if-strings-are-rotations-of-each-other-or-not-1587115620)
-----------------------------------------------------------
Problem Statement:
You are given two strings s1 and s2, of equal lengths. The task is to check if s2 is a rotated version of the string s1.
Note: A string is a rotation of another if it can be formed by moving characters from the start to the end (or vice versa) without rearranging them.
-----------------------------------------------------------
Approach:
To check if one string is a rotation of another, the code uses the KMP algorithm. It doubles the first string (s1 + s1) so that any rotation of s1 would appear as a substring within it. Then, it builds the LPS (Longest Prefix Suffix) array for the second string s2 (treated as the pattern) to optimize the matching process. Using the LPS array, it searches for s2 in the doubled string. If a complete match is found, it confirms s2 is a rotation of s1. 
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        string txt = s1 + s1, pat = s2;
        int len = 0, i = 0, j = 0, k = 1, n = txt.size(), m = pat.size();
        vector<int> lps(m);
        lps[len] = 0;
        while(k < m){
            if(pat[len] == pat[k]){
                len++;
                lps[k] = len;
                k++;
            }
            else{
                if(len != 0){
                    
                    len = lps[len - 1];
                }
                else{
                    lps[k] = 0;
                    k++;
                }
            }
        }
        while(i < n){
            if(pat[j] == txt[i]){
                i++;
                j++;
                if(j == m){
                    return true;
                }
            }
            else{
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }
};

int main() {
    string str1, str2;
    cout << "Enter the text: ";
    getline(cin, str1);
    cout << "Enter the pattern to search: ";
    getline(cin, str2);

    Solution s;
    if (s.areRotations(str1, str2)) {
        cout << "The two strings are a rotation of each other" << endl;
    } else {
        cout << "The two strings are not a rotation of each other";
    }
    return 0;
}