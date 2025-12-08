/* 
Date: December 8, 2025
Platform: LeetCode (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-pairs-whose-sum-is-less-than-target)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.
-----------------------------------------------------------
Approach:
First, sort the array so the numbers fall into a clean increasing line that two pointers can glide across. Then, walk with one pointer at the start and one at the end, and whenever their sum turns out to be smaller than the target, scoop up all pairs formed with that left element by counting everything between the pointers and sliding the left pointer forward. Finally, whenever the sum is too large, just move the right pointer inward to smaller values.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 0;
        
        int l = 0, r = n - 1;
        while(l < r){
            int sum = arr[l] + arr[r];
            if (sum < target){
                count += (r - l);
                l++;
            } else {
                r--;
            }
        }
        
        return count;
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
    int result = s.countPairs(nums, target);

    cout << "The total number of pairs with sum = " << target 
         << " is: " << result << endl;

    return 0;
}