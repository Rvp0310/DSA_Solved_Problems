/* 
Date: December 12, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/longest-distinct-characters-in-string5848)
-----------------------------------------------------------
Problem Statement: 
You are given a string s. You have to find the length of the longest substring with all distinct characters. 
-----------------------------------------------------------
Approach:

-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        unordered_map<int, int> freq;
        int l = 0, maxLen = 0;
        
        for(int r = 0; r < n; r++){
            freq[s[r]]++;
            
            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r - l + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution s;
    string input;

    cout << "Enter a string:\n";
    getline(cin, input);

    int result = s.longestUniqueSubstr(input);

    cout << "Length of longest unique substring: " << result << endl;

    return 0;
}