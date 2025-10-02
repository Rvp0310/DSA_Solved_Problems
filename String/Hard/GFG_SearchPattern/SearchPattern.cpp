/* 
Date: January 6, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/search-pattern0205)
-----------------------------------------------------------
Problem Statement:
Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices.
Note: Return an empty list in case of no occurrences of pattern.
-----------------------------------------------------------
Approach:
First, construct the LPS (Longest Prefix Suffix) array for the pattern to identify how the pattern itself overlaps. This helps determine how far the pattern can shift upon a mismatch, avoiding redundant comparisons. Then, iterate through the text and pattern using two pointers. If characters match, advance both pointers. If the full pattern is matched, store the starting index and use the LPS array to continue searching efficiently. On a mismatch, reset the pattern pointer using the LPS value instead of starting over.
-----------------------------------------------------------
Time Complexity: O(n + m)
Space Complexity: O(m)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
        vector<int> search(string& pat, string& txt) {
            int m = pat.size(), n = txt.size(), len = 0, k = 1;
            vector<int> lps(m);
            vector<int> res;
            lps[len] = 0;
            while(k < m){
                if(pat[k] == pat[len]){
                    len++;
                    lps[k] = len;
                    k++;
                }
                else{
                    if(len != 0){
                        len = lps[len - 1];
                    }
                    else{
                        lps[k] = 0;
                        k++;
                    }
                }
            }
            int i = 0, j = 0;
            while(i < n){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                    if(j == m){
                        res.push_back(i - j);
                        j = lps[j - 1];
                    }
                }
                else{
                    if(j != 0){
                        j = lps[j - 1];
                    }
                    else{
                        i++;
                    }
                }
            }
            return res;
        }
};

int main() {
    string txt, pat;
    cout << "Enter the text: ";
    getline(cin, txt);
    cout << "Enter the pattern to search: ";
    getline(cin, pat);

    Solution s;
    vector<int> result = s.search(pat, txt);

    if (result.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at positions (0-indexed): ";
        for (int pos : result) {
            cout << pos << " ";
        }
        cout << endl;
    }
    return 0;
}