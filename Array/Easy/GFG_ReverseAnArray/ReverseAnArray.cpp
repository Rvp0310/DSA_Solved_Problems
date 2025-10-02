/* 
Date: November 26, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/reverse-an-array)
-----------------------------------------------------------
Problem Statement:
You are given an array of integers arr[]. Your task is to reverse the given array.
Note: Modify the array in place. 
-----------------------------------------------------------
Approach:
Swap elements symmetrically from both ends till the middle to reverse the array in-place, ensuring O(n/2) time and O(1) space — clean, efficient, and memory-safe.
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
    void reverseArray(vector<int> &arr) {
        int n=arr.size(),temp;
        for(int i=0;i<n/2;i++)
        {
            temp=arr[n-1-i];
            arr[n-1-i]=arr[i];
            arr[i]=temp;
        }
    }
};

int main(){
    string input;
    cout << "Enter the array elements (seperated by spaces):" << endl;
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
    s.reverseArray(nums);

    cout << "\nGiven Array Reversed:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    return 0;
}