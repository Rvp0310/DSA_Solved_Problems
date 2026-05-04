/* 
Date: May 4, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/maximize-partitions-in-a-string)
-----------------------------------------------------------
Problem Statement:
Given a string s of lowercase English alphabets, your task is to return the maximum number of substrings formed, after possible partitions (probably zero) of s such that no two substrings have a common character.
-----------------------------------------------------------
Approach:
Store the last occurrence index of each character in the string using an array. Traverse the string while maintaining a variable that tracks the farthest last occurrence of all characters seen so far. For each index i, update this value using the current character’s last occurrence. When the current index matches this farthest boundary, it means all characters in the current segment are fully contained within it, so a partition can be made. Increment the count and continue. This greedy method ensures the maximum number of substrings with no overlapping characters.
-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxPartitions(string &s) {
        vector<int> last(26, -1);
        
        for(int i = 0; i < s.length(); i++){
            last[s[i] - 'a'] = i;
        }
        
        int count = 0, a = -1;
        
        for(int i = 0; i < s.length(); i++){
            a = max(last[s[i] - 'a'], a);
            
            if(a == i){
                count++;
            }
        }
        
        return count;
    }
};

int main() {
    string input;
    cout << "Enter a string:" << endl;
    cin >> input;

    Solution s;
    cout << "\n\nMaximum partition that can divide the given string into substrings with no common characters: " << s.maxPartitions(input) << endl;

    return 0;
}