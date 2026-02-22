/* 
Date: February 15, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-increasing-subsequence-1587115620)
-----------------------------------------------------------
Problem Statement:
Given an array arr[] of non-negative integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).
A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.
-----------------------------------------------------------
Approach:
This problem is solved using Dynamic Programming by defining an array lis where lis[i] stores the length of the longest strictly increasing subsequence ending at index i.
Each element is initially assigned a value of 1 because every single element by itself forms an increasing subsequence of length 1.
For every index i, all previous indices prev from 0 to i - 1 are checked. If arr[i] is greater than arr[prev], it means the current element can extend the increasing subsequence ending at prev. Therefore, lis[i] is updated as max(lis[i], lis[prev] + 1).
After processing all elements, the maximum value in the lis array represents the length of the longest strictly increasing subsequence in the array.
-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
  public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> lis(n, 1);
        
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(arr[i] > arr[prev]){
                    lis[i] = max(lis[i], (lis[prev] + 1));
                }
            }
        }
        
        return *max_element(lis.begin(), lis.end());
    }
};

int main(){
    string s;
    cout << "Enter the elements of array (space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> arr;

    while(ss >> num){
        arr.push_back(num);
    }

    Solution sol;
    cout << "Longest Increasing Subsequence length in given array: " << sol.lis(arr) << endl;
    return 0;
}