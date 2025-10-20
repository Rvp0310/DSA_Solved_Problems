/* 
Date: October 20, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/print-anagrams-together)
-----------------------------------------------------------
Problem Statement:
Given an array of strings, return all groups of strings that are anagrams. The strings in each group must be arranged in the order of their appearance in the original array. Refer to the sample case for clarification.
-----------------------------------------------------------
Approach:
Take each word and sort its letters to create a signature key, so all anagrams share the same key. Push the original word into a group corresponding to that key in a hash map. Finally, collect all the groups from the map — each group now contains all words that are anagrams of each other, preserving their original order within the group.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map <string, vector<string>> mp;\
        for (string w: arr){
            string str = w;
            sort(str.begin(), str.end());
            mp[str].push_back(w);
        }
        vector<vector<string>> res;
        for(auto& pair : mp){
            res.push_back(pair.second);
        }
        return res;
    }
};

int main() {
    string input;
    cout << "Enter the array elements (space-separated strings):" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<string> arr;
    string word;

    while (ss >> word) {
        arr.push_back(word);
    }

    cout << "Given List Of Strings:" << endl;
    for(string &word : arr){
        cout << word << endl;
    }

    Solution s;
    vector<vector<string>> result = s.anagrams(arr);

    cout << "\nGrouped Anagrams:" << endl;
    for (auto& group : result) {
        for (auto& w : group) {
            cout << w << "\t";
        }
        cout << endl;
    }

    return 0;
}