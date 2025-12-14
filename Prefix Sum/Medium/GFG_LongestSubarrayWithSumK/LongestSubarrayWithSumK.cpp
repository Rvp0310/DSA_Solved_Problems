/* 
Date: December 14, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/longest-sub-array-with-sum-k0809)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.
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
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;   // prefix sum -> start index
        int maxLen = 0, sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum == k){
                maxLen = i + 1;
            }
            
            if(mp.find(sum - k) != mp.end()){
                maxLen = max(maxLen, i - mp[sum - k]);
            } 
            
            if(mp.find(sum) == mp.end()){
                mp.insert({sum, i});
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

    int target;
    cout << "Enter the target sum:" << endl;
    cin >> target;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    int result = s.longestSubarray(nums, target);

    if(result == 0){
        cout << "No subarray in given array with sum " << target << endl;
    } else {
        cout << "Longest Subarray with Sum = " << target << " has length " << result << endl;
    }
    
    return 0;
}