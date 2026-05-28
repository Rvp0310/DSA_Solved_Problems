/* 
Date: May 28, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/missing-number-in-array1416)
-----------------------------------------------------------
Problem Statement:
You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.
-----------------------------------------------------------
Approach:
Use the XOR operation to find the missing element. XOR all elements in the array and XOR all numbers from 1 to n. The result will be the missing element.
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
    int missingNum(vector<int>& arr) {
        int n = arr.size(), xor1 = 0, xor2 = 0;
        
        for(int a: arr){
            xor1 ^= a;
        }
        
        for(int i = 1; i <= n + 1; i++){
            xor2 ^= i;
        }
        
        return xor1 ^ xor2;
    }
};

int main(){
    string input;
    cout << "Enter the array elements (seperated by spaces,such that 1 <= arr[i] <= n + 1, and only one missing):" << endl;
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
   
    cout << "\nMissing Element: " << s.missingNum(nums) << endl;

    return 0;
}