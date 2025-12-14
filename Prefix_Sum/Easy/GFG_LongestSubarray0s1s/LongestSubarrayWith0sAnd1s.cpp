/* 
Date: December 14, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/largest-subarray-of-0s-and-1s)
-----------------------------------------------------------
Problem Statement: 
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.
-----------------------------------------------------------
Approach:
The problem is converted into a prefix-sum style task by treating 1 as +1 and 0 as -1. A running count is maintained while traversing the array, and a hashmap stores the first index at which each count value appears. If the same count appears again, the elements between those two indices form a subarray with equal numbers of 0s and 1s, so the length is calculated and the maximum length is updated. The map is initialized with count 0 at index -1 to correctly handle subarrays starting from the beginning.
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
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        mp.insert({0, -1});
        int maxLen = 0, count = 0;
        
        for (int i = 0; i < n; i++) {
            count = count + (arr[i] == 1 ? 1 : -1);
            if (mp.find(count) != mp.end()) {
               maxLen = max(maxLen, i - mp[count]); 
            }
            else {
                mp[count] = i;
            }
        }
        
        return maxLen;
    }
};

int main() {
    string input;
    cout << "Enter the array elements (separated by space):" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> nums;
    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    int result = s.maxLen(nums);

    cout << "Length Of Largest subarray with equal no.of 0s and 1s in given array: " << result << endl;
    
    return 0;
}