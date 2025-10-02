/* 
Date: December 20, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/next-permutation5226)
-----------------------------------------------------------
Problem Statement:
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 
Note:  A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.
-----------------------------------------------------------
Approach:
Find the first decreasing element from the right, swap it with the next greater on its right, then reverse the suffix — generates the next lexicographically greater permutation in-place.
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
    void nextPermutation(vector<int>& arr) {
        int index =- 1,n = arr.size();
        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i] < arr[i+1])
            {
                index = i;
                break;
            }
        }
        
        if(index != -1)
        {
            for(int j = n - 1; j > index; j--)
            {
                if(arr[j] > arr[index])
                {
                    int temp = arr[index];
                    arr[index] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
        }
        for(int p = index+1, q = n - 1; p < q; p++, q--)
        {
            int temp=arr[p];
            arr[p]=arr[q];
            arr[q]=temp;
        }
    }
};

int main(){
    string input;
    cout << "Enter the permutation elements (seperated by spaces):" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nums;
    int num;

    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given permutation:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    Solution s;
    s.nextPermutation(nums);

    cout << "\nNext Permutation:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    return 0;
}