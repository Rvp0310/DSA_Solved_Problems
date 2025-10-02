/* 
Date: December 30, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/smallest-positive-missing-number-1587115621)
-----------------------------------------------------------
Problem Statement:
You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.
Note: Positive number starts from 1. The array can have negative integers too.
-----------------------------------------------------------
Approach:
Replaced all numbers that are either negative or too large to be missing with n + 1, then used the index positions of the array itself to mark which positive numbers exist by making the value at their corresponding positions negative, and finally scanned to find the first index that wasn’t marked negative to return the smallest missing positive number.
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
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            if(arr[i] <= 0|| arr[i] > n)
            {
                arr[i] = n + 1;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            int num = abs(arr[i]);
            if(arr[num-1] > 0 && num <= n)
            {
            arr[num-1] = -arr[num-1];
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > 0)
            {
                return i+1;
            }
        }
        
        return n+1;

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
    cout << "\nThe minimum positive number missing from the array is " << s.missingNumber(nums) << endl;

    return 0;
}