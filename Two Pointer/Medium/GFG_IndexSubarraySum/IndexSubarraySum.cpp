/* 
Date: December 10, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/subarray-with-given-sum-1587115621)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.

Note: If no such array is possible then, return [-1].
-----------------------------------------------------------
Approach:
Because all elements are non-negative, the sliding-window technique works cleanly. Two pointers start at the beginning of the array while a running sum tracks the current window’s total. The right pointer expands the window by adding elements. If the running sum becomes larger than the target, the left pointer shrinks the window by removing elements from the left until the sum is no longer greater than the target. Whenever the running sum matches the target, the current window’s 1-based indices are returned immediately since the task is to find the first valid subarray. If the end of the array is reached without a match, the result is [-1].
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        
        int l = 0, r = 0;
        int curr = 0;
        while(r < n){
            curr += arr[r];
            
            while(curr > target && l <= r){
                curr -= arr[l];
                l++;
            }
            
            if(curr == target){
                return {l + 1, r + 1};
            }
            
            r++;
        }
        
        return {-1};
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
    vector<int> result = s.subarraySum(nums, target);

    if(result[0] == -1){
        cout << "No subarray with sum = " << target << endl;
    } else {
        cout << "The  subarray with sum = " << target << " :" << endl;
        for(int el: result){
            cout << el << endl;
        }
    }
    
    return 0;
}