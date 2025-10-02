/* 
Date: January 15, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/find-h-index--165609)
-----------------------------------------------------------
Problem Statement:
Given an integer array citations[], where citations[i] represents the number of citations for the ith paper, you have to compute the H-index of the researcher.
The H-index is defined as the maximum value H such that the researcher has at least H papers with at least H citations each.
-----------------------------------------------------------
Approach:
For each citation count, increment the corresponding frequency index—if a paper has more than n citations, cap it at freq[n] ,Since the H-index can’t be more than the total number of papers n. Then, iterate from the end of the frequency array, a running total is maintained to track the number of papers that have at least h citations. As soon as this total becomes greater than or equal to h, the corresponding h is returned as the H-index.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1);
        
        for(int i = 0; i < n; i++){
            if (citations[i] >= n){
                freq[n]++;
            }
            else{
                freq[citations[i]]++;
            }
        }
        
        int h = n, count = freq[n];
        while(count < h){
            h--;
            count += freq[h];
        }
        return h;
    }
};

int main() {
    string input;
    cout << "Enter the citation counts of the research papers (space-separated):" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> citations;
    
    while(ss >> num){
        citations.push_back(num);
    }

    Solution s;
    cout << "H-Index: " << s.hIndex(citations) << endl;
    return 0;
}
