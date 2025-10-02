/* 
Date: November 26, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/move-all-zeroes-to-end-of-array0751)
-----------------------------------------------------------
Problem Statement:
You are given an array arr[] of non-negative integers. Your task is to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array.
-----------------------------------------------------------
Approach:
Iterate through the array and moved all non-zero elements to the front while keeping their order, then filled the remaining positions in array with zeros to push all zeros to the end.
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
    void pushZerosToEnd(vector<int>& arr) {
        int l=arr.size(),index=0;
        for(int i = 0; i < l; i++)
        {
            if(arr[i]!=0)
            {
                arr[index++]=arr[i];
            }
        }
        while(index<l)
        {
            arr[index++]=0;
        }
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

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    Solution s;
    s.pushZerosToEnd(nums);
    
    cout << "\nGiven Array after pushing all the zeros to the end:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    return 0;
}