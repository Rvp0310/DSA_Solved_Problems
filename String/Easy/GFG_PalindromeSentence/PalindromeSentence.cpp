/* 
Date: January 26, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/string-palindromic-ignoring-spaces4723)
-----------------------------------------------------------
Problem Statement:
Given a single string s, the task is to check if it is a palindrome sentence or not.
A palindrome sentence is a sequence of characters, such as word, phrase, or series of symbols that reads the same backward as forward after converting all uppercase letters to lowercase and removing all non-alphanumeric characters (including spaces and punctuation).
-----------------------------------------------------------
Approach:
First iterated through the string and kept only alphanumeric characters, discarding spaces and special symbols. Converted all remaining characters to lowercase to ignore case differences. Then reversed the cleaned string and compared it with the original cleaned string. If they were identical, the sentence is a palindrome; otherwise, it’s not.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution{
  public:
    bool sentencePalindrome(string s) {
        string clean;
        for(char c: s){
            if (isalnum(c)) {
                clean += c;
            }
        }
        
        transform(clean.begin(), clean.end(), clean.begin(), ::tolower);
        
        string rev = clean;
        
        reverse(rev.begin(), rev.end());
        
        return rev == clean;
    }
};


int main() {
    Solution sol;
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);

    if(sol.sentencePalindrome(input)){
        cout << "The sentence is a palindrome (ignoring symbols and space)." << endl;
    } else {
        cout << "The sentence is NOT a palindrome." << endl;
    }

    return 0;
}
