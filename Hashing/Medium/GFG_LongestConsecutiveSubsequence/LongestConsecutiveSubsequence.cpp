/* 
Date: October 18, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/longest-consecutive-subsequence2449)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
-----------------------------------------------------------
Approach:
An unordered_set is created from the array elements to ensure uniqueness and allow O(1) lookups.
For each element, the function checks if it marks the beginning of a sequence (i.e., its predecessor num-1 is absent).
If so, it continuously increments from that number while consecutive numbers exist in the set.
This count represents the length of the current consecutive sequence.
The maximum of all such lengths is stored and returned as the result.
Using an unordered_set eliminates the need for sorting, achieving an O(n) average time complexity.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
       unordered_set<int> lookup(arr.begin(), arr.end());

        int maxLen = 0;
        for(int num : lookup){
            if (!lookup.count(num - 1)){
                int current = num, l = 0;

                while(lookup.count(current + 1)){
                    current++;
                    l++;
                }

                maxLen = max(l, maxLen);
            }
        }
        return maxLen;
    }
};

int main(){
    string input;
    cout << "Enter the elements of the array (separated by space):" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nums;
    int num;
   
    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given Array:" << endl;
    for(int num : nums){
        cout << num <<"\t";
    }

    Solution s;
    int r = s.longestConsecutive(nums);
    cout << "\nLongest Common Subsequence Length is: " << r << endl;

    return 0;
}
