/* 
Date: March 20, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/subset-sum-problem-1611555638)
-----------------------------------------------------------
Problem Statement:
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 
-----------------------------------------------------------
Approach:
First compute total sum of array; if it’s odd, equal split is impossible so return false. Otherwise, reduce the problem to checking if there exists a subset with sum = total/2. Use DP where each state tells whether a certain sum is achievable using elements so far. For each element, either include it or skip it and update reachable sums accordingly. If sum/2 becomes achievable at the end, the array can be split into two equal subsets.
-----------------------------------------------------------
Time Complexity: O(n * sum)
Space Complexity: O(sum)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
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

    cout << "Enter the expected sum:" << endl;
    cin >> num;

    Solution sol;
    if(sol.isSubsetSum(nums, num)){
        cout << "Subset with sum " << num << " exists in given array." << endl;
    } else {
       cout << "Subset with sum " << num << " does not exists in given array." << endl; 
    }
    return 0;
}