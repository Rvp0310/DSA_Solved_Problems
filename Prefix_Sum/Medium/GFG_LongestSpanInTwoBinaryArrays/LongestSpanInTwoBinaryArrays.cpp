/* 
Date: June 24, 2026
Platform: GeeksForGeeks https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1?page=1&category=prefix-sum&sortBy=submissions)
-----------------------------------------------------------
Problem Statement: 
Given two binary arrays, a1[] and a2[] of equal length. Find the length of longest common span (i, j), where i<= j such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].
-----------------------------------------------------------
Approach:
Maintain prefix sums of both arrays and store the first occurrence of their difference in a hash map. If the same difference appears again, the span between the two occurrences has equal sums in both arrays. Track the maximum such span length.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size(), pfs1 = 0, pfs2 = 0, maxLen = 0;
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            pfs1 += a1[i];
            pfs2 += a2[i];
            
            if(pfs1 == pfs2){
                maxLen = max(maxLen, i + 1);
            }
            
            int currDiff = pfs1 - pfs2;
            if(mp.find(currDiff) != mp.end()){
                maxLen = max(maxLen, i - mp[currDiff]);
            } else {
                mp[currDiff] = i;
            }
        }
        
        return maxLen;
    }
};

int main() {
    string input;
    cout << "Enter the first binary array elements (separated by space):" << endl;
    getline(cin, input);

    stringstream ss1(input);
    int num;
    vector<int> nums1;
    while(ss1 >> num){
        nums1.push_back(num);
    }

    cout << "Enter the second binary array elements (separated by space, must be equal in length as previous array):" << endl;
    vector<int> nums2(nums1.size());
    for(int i =  0; i < nums1.size(); i++){
        int n;
        cin >> n;
        nums2[i] = n;
    }

    cout << "Given Arraya:" << endl;
    for(int i = 0; i < nums1.size(); i++){
        cout << nums1[i] << "\t";
    }
    cout << endl;
    for(int i = 0; i < nums2.size(); i++){
        cout << nums2[i] << "\t";
    }
    cout << endl;

    Solution s;

    cout << "Longest Span with equal sum in given binary arrays: " << s.equalSumSpan(nums1, nums2);
    
    return 0;
}