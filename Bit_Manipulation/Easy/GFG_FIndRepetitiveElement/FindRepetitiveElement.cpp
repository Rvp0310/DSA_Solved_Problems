/* 
Date: May 28, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/find-repetitive-element-from-1-to-n-1)
-----------------------------------------------------------
Problem Statement:
You are given an array of integers arr[]. Your task is to find the repetitive element in the array.
Note: The array contains elements from 1 to n-1, and one element is repeated.
-----------------------------------------------------------
Approach:
Use the XOR operation to find the repetitive element. XOR all elements in the array and XOR all numbers from 1 to n-1. The result will be the repetitive element.
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
    int findDuplicate(vector<int>& arr) {
        int n = arr.size(), res = 0;
        
        for(int i = 0; i < n - 1; i++){
            res = res ^ (i + 1) ^ arr[i];
        }
        
        res = res ^ arr[n - 1];
        
        return res;
    }
};

int main(){
    string input;
    cout << "Enter the array elements (seperated by spaces,such that 1 <= arr[i] < n, and only one repeated):" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nums;
    int num;

    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    Solution s;
   
    cout << "\nRepetitive Element: " << s.findDuplicate(nums) << endl;

    return 0;
}