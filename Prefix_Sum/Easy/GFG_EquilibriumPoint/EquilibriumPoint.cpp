/* 
Date: December 14, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/equilibrium-point-1587115620)
-----------------------------------------------------------
Problem Statement: 
Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 
-----------------------------------------------------------
Approach:
The total sum of the array is calculated first. A running prefix sum is then maintained while moving through the array, excluding the current index. For each index, the suffix sum is obtained by subtracting the prefix sum and the current element from the total sum. If the prefix sum and suffix sum are equal, that index is the equilibrium point and is returned immediately since the first such index is required. If no index satisfies this condition, the result is -1.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size(), res = -1, total = reduce(arr.begin(), arr.end()), prefix = 0;
        
        for(int i = 1; i < n - 1; i++){
            prefix += arr[i - 1];
            int suffix = total - prefix - arr[i];
            if(prefix == suffix){
                return i;
            }
        }
        
        return -1;
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
    int result = s.findEquilibrium(nums);

    if(result == -1){
        cout << "No equilibrium point in given array." << endl;
    } else {
        cout << "Equilibrium point in given array: " << result << endl;
    }
    
    return 0;
}