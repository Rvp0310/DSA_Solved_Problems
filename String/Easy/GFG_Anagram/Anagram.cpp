/* 
Date: January 3, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/anagram-1587115620)
-----------------------------------------------------------
Problem Statement:
Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not. Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order. 
-----------------------------------------------------------
Approach:
First, check if the lengths of the two strings are unequal — if yes, they can't be anagrams. Then, convert both strings to lowercase to make the comparison case-insensitive. Sort the characters of both strings and compare them — if the sorted versions match, the original strings are anagrams.
-----------------------------------------------------------
Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        if(s1.length()!=s2.length())
        {
            return false;
        }
        string str1=s1,str2=s2;
        transform(str1.begin(),str1.end(),str1.begin(),::tolower);
        transform(str2.begin(),str2.end(),str2.begin(),::tolower);
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        return str1==str2;
    }
};

int main(){
    string s1, s2;
    cout << "Enter a string:" << endl;
    getline(cin, s1);
    cout << "Enter another string:" << endl;
    getline(cin, s2);
    Solution s;
    if(s.areAnagrams(s1, s2)){
        cout << "The entered strings are an Anagram." << endl;
    }
    else {
        cout << "The entered strings are not an Anagram." << endl;
    }
    return 0;
}