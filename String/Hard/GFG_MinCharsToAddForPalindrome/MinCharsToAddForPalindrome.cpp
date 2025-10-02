/* 
Date: January 8, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/minimum-characters-to-be-added-at-front-to-make-string-palindrome)
-----------------------------------------------------------
Problem Statement:
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.
Note: A palindrome string is a sequence of characters that reads the same forward and backward.
-----------------------------------------------------------
Approach:
To find the minimum characters to add at the front to make the string a palindrome, reverse the string and concatenate it to the original with a separator like "$" in between. Construct the LPS array of this new string using the KMP algorithm. The last value in the LPS array indicates the longest palindromic prefix matched in the original string. Subtracting this length from the original string’s total length gives the required answer.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
        int minChar(string& s) {
            string rev = s;
            reverse(rev.begin(), rev.end());
            string txt = s + '$' + rev;
            int len = 0, m = s.size(), n = txt.size(), i = 1;
            vector<int> lps(n);
            
            while(i < n){
                if(txt[i] == txt[len]){
                    len++;
                    lps[i] = len;
                    i++;
                }
                else{
                    if(len != 0){
                        len = lps[len - 1];
                    }
                    else{
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            
            return m - lps.back();
        }
};

int main() {
    string input;
    cout << "Enter a string:" << endl;
    cin >> input;

    Solution s;
    cout << "Minimum characters to add at front to make it palindrome: " << s.minChar(input) << endl;

    return 0;
}