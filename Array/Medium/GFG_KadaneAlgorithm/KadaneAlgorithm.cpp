/* 
Date: December 25, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/kadanes-algorithm-1587115620)
-----------------------------------------------------------
Problem Statement:
You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].
Note : A subarray is a continuous part of an array.
-----------------------------------------------------------
Approach:
at each step, pick the maxmimum between extending the sum(i.e current element + the current result) or starting fresh(the current elemnent) — track global max for an optimal O(n) solution.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size(), currsum = 0, maxsum = INT_MIN;
        for(int i=0;i<n;i++)
        {
            currsum=max(currsum+arr[i],arr[i]);
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
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
    cout << "\nThe maximum subarray sum for the given array is " << s.maxSubarraySum(nums) << endl;

    return 0;
}