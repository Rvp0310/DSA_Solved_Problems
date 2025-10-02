/* 
Date: February 7, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/key-pair5616)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target.
-----------------------------------------------------------
Approach:
Traverse the array while keeping track of elements seen so far in a hash set.
For each element arr[i], check if target - arr[i] already exists in the set.
If yes, a valid pair is found. Otherwise, insert the current element into the set and continue.
If no pair is found by the end, return false.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_set <int> seen;
        for(int i = 0; i < arr.size(); i++){
            if(seen.find(target - arr[i]) != seen.end()){
                return true;
            }
            seen.insert(arr[i]);
        }
        return false;
    }
};

int main(){
    string input;
    cout << "Enter the array elements (separated by space)" << endl;
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

    Solution s;

    if(s.twoSum(nums, target)){
        cout << "\nThe pair of numbers whose sum is equal to " << target << " is present in the given array." << endl;
    }
    else {
        cout << "\nThe pair of numbers whose sum is equal to " << target << " is not present in the given array." << endl;
    }
    return 0;
}