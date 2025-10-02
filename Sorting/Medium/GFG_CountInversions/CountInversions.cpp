/* 
Date: January 21, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/inversion-of-array-1587115620)
-----------------------------------------------------------
Problem Statement:
Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].
-----------------------------------------------------------
Approach:
Apply a modified merge sort by spliting the array recursively until each part has one element. During the merge step, compare elements from both halves. If an element from the left is greater than one from the right, all remaining elements in the left subarray form an inversion with that right-side element. Add that count to the total. Merging continues as usual to maintain sorting. The sum of such counts across all merges gives the total inversion count.
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
    int inversionCount(vector<int> &arr) {
       int n = arr.size();
       int count = divide(arr, 0, n - 1);
       return count;
    }
    
    int divide(vector<int>& arr, int l, int r){
       int c = 0;
       if(l < r){
           int m = (l + r) / 2;
           c += divide(arr, l, m);
           c += divide(arr, m + 1, r);
           
           c += mergeSort(arr, l, m, r);
       } 
       return c;
    }
    
    int mergeSort(vector<int>& arr, int l,int m, int r){
        int nl = m - l + 1, nr = r - m;
        vector<int> L(nl), R(nr);
        
        for(int i = 0; i < nl; i++){
            L[i] = arr[l + i];
        }
        for(int j = 0; j < nr; j++){
            R[j] = arr[m + 1 +j];    
        }
        
        int i = 0, j = 0, k = l, inv = 0;
        while(i < nl && j < nr){
            if(L[i]<=R[j]){
                arr[k++] = L[i++];
            }
            else{
                arr[k++] = R[j++];
                inv += (nl - i);
            }
        }
        
        while(i < nl){
            arr[k++] = L[i++];
        }
        while(j < nr){
            arr[k++] = R[j++];
        }
        
        return inv;
    }
};

int main() {
    string input;
    cout << "Enter the array elements (separated by spaces):" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> arr;
    
    while(ss >> num){
        arr.push_back(num);
    }
    
    Solution s;
    cout << "Number of inversions: " << s.inversionCount(arr) << endl;

    return 0;
}