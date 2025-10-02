/* 
Date: February 3, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-matrix-1587115621)
-----------------------------------------------------------
Problem Statement: 
Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.
-----------------------------------------------------------
Approach:
Treat the 2D matrix as a flattened 1D sorted array of size n * m.
Apply binary search on this virtual array by mapping the 1D index back to 2D indices using:
-> Row = mid / m
-> Column = mid % m

Check the middle element each time and adjust search bounds until the target is found or the search space is empty.
-----------------------------------------------------------
Time Complexity: O(log (n *m))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size(), lo = 0, hi = (n*m) - 1;
        while(lo <= hi){
            int mid = (lo + hi)/2, el = mat[mid / m][mid % m];
            if(el == x){
                return true;
            }
            else if (el > x){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    int n, m;
    cout << "Enter the no.of rows in the matrix:" << endl;
    cin >> n;
    cout << "Enter the no.of columns in the matrix:" << endl;
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements of the matrix (row-wise):" << endl;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    int t;
    cout << "Enter the element to search for:" << endl;
    cin >> t;
    cout << "Given Matrix:" << endl;
    for (const auto& r : matrix){
        for (int el : r){
            cout << el << " ";
        }
        cout << endl;
    }
    Solution s;
    if(s.searchMatrix(matrix, t)){
        cout << t << " is present in the matrix." << endl;
    }
    else{
        cout << t << " is not present in the matrix." << endl;
    }
    return 0;
}