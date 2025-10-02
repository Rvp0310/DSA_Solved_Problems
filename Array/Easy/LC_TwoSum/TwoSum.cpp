/* 
Date: June 7, 2025
Platform: Leetcode (https://leetcode.com/problems/two-sum/)
-----------------------------------------------------------
Problem Statement:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order. 
-----------------------------------------------------------
Approach:
Store each value-to-index pair in a hash map while traversing, and for every element, check if the complement (target - current) already exists — ensures O(n) time with clean constant-time lookups.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {i, mp[complement]};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main() {
    Solution s;

    vector<int> nums;
    int target;
    string input;

    cout << "Enter the array elements (separated by space):"<< endl;
    getline(cin, input);

    if (input.empty()) {
        cout << "No input received. Exiting." << endl;
        return 1;
    }
    
    stringstream ss(input);
    int num;
    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Enter the Target element:" << endl;
    cin >> target;

    vector<int> result = s.twoSum(nums, target);

    if (result[0] != -1) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two elements found with the given target." << endl;
    }

    return 0;
}

