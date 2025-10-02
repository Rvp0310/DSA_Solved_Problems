/* 
Date: January 24, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/merge-two-sorted-arrays-1587115620)
-----------------------------------------------------------
Problem Statement:
Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.
-----------------------------------------------------------
Approach:
First, sort both arrays. Then use a merge step like in merge sort to combine them into one sorted array. Finally, overwrite a and b with the first n and last m elements of the merged array, respectively.
-----------------------------------------------------------
Time Complexity: O(n log n + m log m)
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
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m =b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> merge(n+m);
        int i = 0, j = 0, left = 0;
        while(i < n && j < m){
            if(a[i] < b[j]){
                merge[left++] = a[i++];
            }else{
               merge[left++] = b[j++]; 
            }
        }
        while(i < n){
            merge[left++] = a[i++];
        }
        while(j < m){
            merge[left++] = b[j++];
        }
        int p = 0, q = 0, start = 0;
        while(p<n){
            a[p++] = merge[start++];
        }
        while(q<m){
            b[q++] = merge[start++];
        }
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
    printArray(nums1, "\nFirst Array:");
    printArray(nums2, "\nSecond Array:");

    Solution s;
    s.mergeArrays(nums1, nums2);

    printArray(nums1, "\nFirst Array after merge:");
    printArray(nums2, "\nSecond Array after merge:");

    return 0;
}