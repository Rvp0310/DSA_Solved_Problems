/* 
Date: January 30, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/kth-missing-positive-number-in-a-sorted-array7)
-----------------------------------------------------------
Problem Statement:
Given a sorted array of distinct positive integers arr[], You need to find the kth positive number that is missing from the arr[].
-----------------------------------------------------------
Approach:
Used binary search on the sorted array to determine how many numbers are missing before each index. Compared the actual value at mid with the expected value (mid + k) to decide whether the k-th missing number lies to the left or right. Adjusted the search boundaries accordingly, and once the search ended, returned the calculated position as the k-th missing positive number.
-----------------------------------------------------------
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size(), l = 0, r = n - 1, res = n + k;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(arr[m] > m + k){
                res = m + k;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return res;
    }
};

int main(){
    string input;
    cout << "Enter a sorted array elements (separated by space):" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> nums;
    while(ss >> num){
        nums.push_back(num);
    }

    int k;
    cout << "Enter k:" << endl;
    cin >> k;

    cout << "Given Array:" << endl;
    for (const auto& el: nums){
        cout << el << "\t";
    }

    Solution s;
    cout << "\nThe " << k <<"-th missing positive number from given array is " << s.kthMissing(nums, k) <<endl;
    return 0;
}