/* 
Date: December 19, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/permutations-of-a-given-string2041)
-----------------------------------------------------------
Problem Statement:
Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.
-----------------------------------------------------------
Approach:
First, sort the given string so that identical characters are placed together and permutations are generated in a fixed order. Then repeatedly generate the next possible permutation using the next_permutation function, which rearranges the string into the next lexicographically greater arrangement. Each time a new permutation is formed, store it in the result list. This process automatically avoids duplicate permutations because next_permutation handles repeated characters correctly when the string is initially sorted. Continue this until no further permutations are possible, and finally return the collected list of all unique permutations.
-----------------------------------------------------------
Time Complexity: O(n!)
Space Complexity: O(n^2)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> findPermutation(string &s) {
        vector<string> res;
        sort(s.begin(), s.end());
        do{
            res.push_back(s);
        }while(next_permutation(s.begin(), s.end()));
        
        return res;
    }
};

int main() {
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);

    Solution s;
    vector<string> r = s.findPermutation(input);
    
    cout << "All permutation of given string in order:" << endl;
    for(string el : r){
        cout << el << endl;
    }

    return 0;
}
