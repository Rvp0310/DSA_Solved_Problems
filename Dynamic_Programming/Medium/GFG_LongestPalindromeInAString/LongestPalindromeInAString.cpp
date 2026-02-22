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
This solution finds the longest palindromic substring using the expand-around-center technique. The idea is that every palindrome is centered around a character or between two characters.
For each index i, two cases are checked: one where the palindrome length is odd (center at i) and one where it is even (center between i and i+1). For both cases, two pointers low and high are initialized and expanded outward as long as the characters at those positions are equal and within bounds.
Whenever a longer palindrome is found during expansion, its starting index and length are updated. After checking all possible centers, the substring starting at start with length maxLen is returned as the longest palindromic substring.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string longestPalindrome(string &s) {
        int n = s.length(), start = 0, maxLen = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                int low = i, high = i + j;
                while(low >= 0 && high < n && s[low] == s[high]){
                    int len = high - low + 1;
                    if(len > maxLen){
                        maxLen = len;
                        start = low;
                    }
                    
                    low--;
                    high++;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};

int main(){
    string s;
    cout << "Enter a string:" << endl;
    getline(cin, s);

    Solution sol;
    cout << "Longest palindrome in given string: " << sol.longestPalindrome(s) << endl;
    return 0;
}