/* 
Date: January 25, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/k-th-element-of-two-sorted-array1317)
-----------------------------------------------------------
Problem Statement:
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.
-----------------------------------------------------------
Approach:
Merge both sorted arrays using two pointers. At each step, insert the smaller of the two current elements into a new array. Continue until all elements are merged. The k-th element in the merged array is the answer.
-----------------------------------------------------------
Time Complexity: O(log (min(a, b)))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        vector<int> ans(n + m);
        int i = 0, j = 0, left = 0;
        while(i < n && j < m){
            if(a[i] <= b[j]){
                ans[left++] = a[i++];
            }
            else{
                ans[left++] = b[j++];
            }
        }
        while(i < n){
            ans[left++] = a[i++];
        }
        while(j < m){
            ans[left++] = b[j++];
        }
        return ans[k - 1];
    }
};

vector<int> readArray(const string& prompt) {
    cout << prompt << endl;
    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<int> result;
    int num;

    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

void printArray(const vector<int>& arr, const string& label) {
    cout << label << endl;
    for (int num : arr) {
        cout << num << "\t";
    }
    cout << endl;
}

int main(){
    vector<int> nums1 = readArray("Enter the first array elements (separated by space):");
    vector<int> nums2 = readArray("Enter the second array elements (separated by space):");

    int k;
    cout << "Enter index k to search for in combine sorted array:" << endl;
    cin >> k;

    printArray(nums1, "\nFirst Array:");
    printArray(nums2, "\nSecond Array:");

    Solution s;
    cout << "\nThe " << k << "-th element in combine sorted array is " << s.kthElement(nums1, nums2, k);

    return 0;
}