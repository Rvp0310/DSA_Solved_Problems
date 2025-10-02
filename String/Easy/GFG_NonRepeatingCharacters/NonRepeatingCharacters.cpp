/* 
Date: January 4, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/non-repeating-character-1587115620)
-----------------------------------------------------------
Problem Statement:
Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.
-----------------------------------------------------------
Approach:
First, convert the entire string to lowercase to handle case insensitivity. Then, use a frequency array to count how many times each character appears. After counting, loop through the original string again and return the first character that has a frequency of exactly one. If no such character exists, return '$' as a fallback.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        const int MAX_CHAR = 26;
        vector<int> freq(MAX_CHAR, 0);
        transform(s.begin(), s.end(), s.begin(), ::tolower);   //just-in-case
        for(char c: s)
        {
            freq[c - 'a']++;
        }
        for(char c: s){
            if(freq[c - 'a'] == 1){
                return c;
            }
        }
        // if first as per english characters
        // for(int i = 0; i < s.length(); i++){
        //     if(freq[s[i] - 'a'] == 1)
        //     {
        //         return s[i];
        //     }
        // }
        return '$';
    }
};

int main(){
    string input;
    cout << "Enter any string:" << endl;
    getline(cin, input);
    Solution s;
    cout << "The first non-repeating character in string is " << s.nonRepeatingChar(input) << endl;
}