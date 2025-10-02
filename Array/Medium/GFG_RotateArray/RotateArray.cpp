/* 
Date: December 02, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/rotate-array-by-n-elements-1587115621)
-----------------------------------------------------------
Problem Statement:
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.
Note: Consider the array as circular.
-----------------------------------------------------------
Approach:
Reverse the first d elements to isolate the rotation chunk, reverse the remaining n - d to reorder the rest, and finally reverse the full array to place all elements in their rotated positions.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n=arr.size(),temp[d];
        d=d%n;
        if (d==0)
        {
            return;
        }
        else
        {
        reverse(arr.begin(),arr.begin()+d);
        reverse(arr.begin()+d,arr.end());
        reverse(arr.begin(),arr.end());
        }
    }
};

int main(){
    string input;
    cout << "Enter the array elements:" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nums;
    int num;

    while(ss >> num){
        nums.push_back(num);
    }

    int r;
    cout << "No.of spaces to rotate by from right:" << endl;
    cin >> r; 

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    Solution s;
    s.rotateArr(nums, r);

    cout << "Rotated Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    return 0;
}