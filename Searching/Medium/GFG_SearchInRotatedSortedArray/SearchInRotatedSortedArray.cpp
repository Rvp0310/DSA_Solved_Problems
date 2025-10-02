/* 
Date: January 25, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/search-in-a-rotated-array4618)
-----------------------------------------------------------
Problem Statement:
A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 
-----------------------------------------------------------
Approach:
Since the array is a rotated sorted array, use modified binary search. At each step, check which half is sorted: left to mid or mid to right. If left half is sorted, check if target lies within it. If yes, discard right half, else discard left half. If right half is sorted, check if target lies within it. If yes, discard left half, else discard right half. Repeat until target is found or pointers cross.
-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int l = 0, r = arr.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(arr[mid] == key){
                return mid;
            }
            else if(arr[l] <= arr[mid]){
                if(arr[mid] > key && key >= arr[l]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(arr[mid] < key && key <= arr[r]){
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
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

    int t;
    cout << "Enter the target value:" <<endl;
    cin >> t;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    Solution s;
    cout << "\n" << t << " is found in above array at index " << s.search(nums, t) << endl;
    return 0;
}