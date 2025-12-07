/* 
Date: December 7, 2025
Platform: LeetCode (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/subarrays-with-sum-k)
-----------------------------------------------------------
Problem Statement: 
Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.
-----------------------------------------------------------
Approach:
First, keep a running sum of the elements as you scan the array and treat that running sum as your anchor. Then, whenever this running sum matches the target or has a past prefix that would complete the target when subtracted, count those moments by checking a hashmap that stores how often each prefix sum has appeared. Finally, update the hashmap with the current running sum and continue walking forward, letting the map quietly track all earlier sums so every valid subarray is caught in one smooth pass.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSums;
        int currSum = 0, res = 0;
        
        for(int el: arr){
            currSum += el;
            
            if(currSum == k){
                res++;
            }
            
            if(prefixSums.find(currSum - k) != prefixSums.end()){
                res += prefixSums[currSum - k];
            }
            
            prefixSums[currSum]++;
        }
        
        return res;
    }
};

int main(){
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
    cout << "Enter the target element:" << endl;
    cin >> target;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    int result = s.cntSubarrays(nums, target);

    cout << "The total number of subarrays with sum = " << target 
         << " is: " << result << endl;

    return 0;
}