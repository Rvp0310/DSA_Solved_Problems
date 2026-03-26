/* 
Date: March 26, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/word-break1352)
-----------------------------------------------------------
Problem Statement:
You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

Note: From dictionary[], any word can be taken any number of times and in any order.
-----------------------------------------------------------
Approach:
A dp array is used where dp[i] means the substring from index 0 to i-1 can be formed using dictionary words. Start with dp[0] = 1 (empty string is always valid), then for every position i, try every word in the dictionary and check if it can end at i (so its length fits and matches the substring ending at i). If yes, and the part before it (dp[start]) was already valid, then dp[i] becomes true. The moment any word works, break and move forward. In the end, dp[n] tells whether the whole string can be formed or not.
-----------------------------------------------------------
Time Complexity: O(n ^ 2)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.length();
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(string& w: dictionary){
                int len = w.size();
                int start = i - len;
                
                if(start >= 0 && dp[start] && s.substr(start, len) == w){
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};

int main(){
    string s;
    cout << "Enter the list of strings (space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    string word;
    vector<string> words;

    while(ss >> word){
        words.push_back(word);
    }

    cout << "Enter target string:" << endl;
    getline(cin, s);

    Solution sol;
    if(sol.wordBreak(s, words)){
        cout << "Given String can be formed from given list." << endl;
    } else {
        cout << "Given String can not be formed from given list." << endl;
    }

    return 0;
}