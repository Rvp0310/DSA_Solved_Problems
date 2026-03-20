/* 
Date: March 20, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/subset-sum-problem2014)
-----------------------------------------------------------
Problem Statement:
Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

Note: Each element must be in exactly one subset.
-----------------------------------------------------------
Approach:
First compute total sum of array; if it’s odd, equal split is impossible so return false. Otherwise, reduce the problem to checking if there exists a subset with sum = total/2. Use DP where each state tells whether a certain sum is achievable using elements so far. For each element, either include it or skip it and update reachable sums accordingly. If sum/2 becomes achievable at the end, the array can be split into two equal subsets.
-----------------------------------------------------------
Time Complexity: O(n * sum(arr))
Space Complexity: O(sum(arr))
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size(), sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum % 2 != 0){
            return false;
        }
        
        sum /= 2;
        
        vector<bool> prev(sum + 1, false), curr(sum + 1);
        prev[0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(j < arr[i - 1]){
                    curr[j] = prev[j];
                } else {
                    curr[j] = (prev[j] || prev[j - arr[i - 1]]);
                }
            }
            prev = curr;
        }
        
        return prev[sum];
    }
};

int main(){
    string s;
    cout << "Enter elements of array (space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> nums;

    while(ss >> num){
        nums.push_back(num);
    }

    Solution sol;
    if(sol.equalPartition(nums)){
        cout << "2 Subsets with equal sum exists in given array." << endl;
    } else {
       cout << "2 Subsets with equal sum does not exists in given array." << endl; 
    }
    return 0;
}