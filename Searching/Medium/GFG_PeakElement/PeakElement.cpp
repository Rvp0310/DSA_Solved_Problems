/* 
Date: January 25, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/peak-element)
-----------------------------------------------------------
Problem Statement:
You are given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist).
If there are multiple peak elements, Return index of any one of them. The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".
Note: Consider the element before the first element and the element after the last element to be negative infinity.
-----------------------------------------------------------
Approach:
Check if the first or last element is a peak directly. If not, apply binary search between index 1 and n - 2. At each step, check if mid is greater than both neighbors — if yes, return mid. If mid is less than its right neighbor, move to right half. Else, move to left half.
-----------------------------------------------------------
Time Complexity: O(log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        if(arr[0] > arr[1]){
            return 0;
        }
        else if(arr[n - 1]> arr[n - 2]){
            return n - 1;
        }
        else{
            int l = 1, r = n - 2;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
                    return mid;
                }
                else if(arr[mid] < arr[mid + 1]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return 0;
    }
};

int main(){
    string input;
    cout << "Enter the array elements (separated by spaces):" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> nums;
    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given Array:" << endl;
    for (const auto& el : nums){
        cout << el << "\t";
    }
    
    Solution s;
    cout << "\nThe peak element in the array is at index " << s.peakElement(nums) << endl;
    return 0;
}