/* 
Date: February 15, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-string-chain)
-----------------------------------------------------------
Problem Statement:
You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB. For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k = 1.

Return the length of the longest possible word chain with words chosen from the given list of words in any order.
-----------------------------------------------------------
Approach:

-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
  public:
  
    bool static cmp(string& a, string& b){
        return a.size() < b.size();
    }
    
    int longestStringChain(vector<string>& words) {
        int res = 1;
        unordered_map<string, int> dp;
        
        sort(words.begin(), words.end(), cmp);
        
        for(string w: words){
            dp[w] = 1;
            
            for(int i = 0; i < w.size(); i++){
                string pred = w.substr(0, i) + w.substr(i + 1);
                
                if(dp.find(pred) != dp.end()){
                    dp[w] = max(dp[w], (dp[pred] + 1));
                }
            }
            
            res = max(res, dp[w]);
        }
        
        return res;
    }
};

int main(){
    string s;
    cout << "Enter the elements of array (space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    string word;
    vector<string> arr;

    while(ss >> word){
        arr.push_back(word);
    }

    Solution sol;
    cout << "Longest Increasing Subsequence length in given array: " << sol.longestStringChain(arr) << endl;
    return 0;
}