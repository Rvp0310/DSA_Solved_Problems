/* 
Date: January 24, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/minimum-element-in-a-sorted-and-rotated-array3611)
-----------------------------------------------------------
Problem Statement:
A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 
-----------------------------------------------------------
Approach:
Optimally, use binary search to find the minimum element in the rotated sorted array. At each step, compare the middle element with the rightmost element. If the middle is greater than the right, the minimum lies in the right half, so move the left pointer to mid + 1. Otherwise, the minimum lies in the left half or could be the middle itself, so move the right pointer to mid. Continue this until the left and right pointers meet — that position holds the minimum element.
In brute force method, just sort the rotated array and return the first element — that’ll be the minimum.
-----------------------------------------------------------
Time Complexity: O(log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr){
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return arr[low];
    }

    //brute force
    // int findMin(vector<int>& arr) {
    //     sort(arr.begin(), arr.end());
    //     return arr[0];
    // }
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
    cout << "\nThe minimum element from this rotated array is " << s.findMin(nums) << endl;
    return 0;
}