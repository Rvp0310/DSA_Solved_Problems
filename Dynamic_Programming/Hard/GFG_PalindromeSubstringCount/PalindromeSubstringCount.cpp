/* 
Date: March 5, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/count-palindrome-sub-strings-of-a-string0652)
-----------------------------------------------------------
Problem Statement:
Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2.

Note: A substring is palindromic if it reads the same forwards and backwards.
-----------------------------------------------------------
Approach:
The idea is to use Manacher’s algorithm to detect all palindromic substrings in linear time. The original string is first transformed by inserting a separator # between every character and adding boundary characters ^ at the beginning and $ at the end. This transformation ensures that both even-length and odd-length palindromes can be handled uniformly, because every palindrome in the modified string will have a single center.

An array P is maintained where P[i] represents the radius of the longest palindrome centered at index i in the modified string. Two variables C and R track the center and the right boundary of the rightmost palindrome found so far. For each position i, the mirror position with respect to the current center is calculated. If i lies inside the current right boundary, the previously computed information from the mirror position is used to initialize P[i] so that unnecessary comparisons are avoided.

From this initial radius, the algorithm expands outward while the characters on both sides match, increasing the palindrome radius. If the palindrome centered at i extends beyond the current right boundary, the center and boundary are updated accordingly.

After processing all positions, the values in P indicate how many palindromes exist around each center in the transformed string. These are summed to count the palindromic substrings. Since the problem requires substrings of length at least two, the single-character palindromes corresponding to the original string length are subtracted from the final count.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int countPS(string &s) {
        string ms = "^";
        
        for(auto c: s){
            ms += "#";
            ms += c;
        }
        
        ms += "#$";
        int n = ms.length();
        vector<int> P(n, 0);
        int C = 0, R = 0;
        
        for (int i = 1; i < n - 1; i++){
            int mir = (C * 2) - i;
            
            if(i < R){
                P[i] = min(R - i, P[mir]);
            }
            
            while(ms[i + 1 + P[i]] == ms[i - 1 - P[i]]){
                P[i]++;
            }
            
            if(i + P[i] > R){
                C = i;
                R = i + P[i];
            }
        }
        
        int count = 0;
        for (int i = 1; i < n - 1; i++){
            count += (P[i] + 1) / 2;
        }
        
        return (count - s.length());
    }
};

int main(){
    string s;
    cout << "Enter a string:" << endl;
    getline(cin, s);

    Solution sol;
    cout << "No.of Palindromic Substring in given string are: " << sol.countPS(s) << endl;
    return 0;
}