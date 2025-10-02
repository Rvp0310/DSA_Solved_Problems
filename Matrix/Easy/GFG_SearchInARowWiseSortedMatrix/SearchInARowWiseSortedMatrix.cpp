/* 
Date: February 4, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-row-wise-sorted-matrix)
-----------------------------------------------------------
Problem Statement: 
Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.
Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1].
-----------------------------------------------------------
Approach:
Since each row is individually sorted, iterate through all rows of the matrix.
For each row, apply a binary search (or use std::find as in this code) to check if the target element exists in that row.
If found, return true. If no row contains the element, return false.
-----------------------------------------------------------
Time Complexity: O(n log m)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++){
            if(find(mat[i].begin(), mat[i].end(), x) != mat[i].end()){
                return true;
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
    if(s.searchRowMatrix(matrix, t)){
        cout << t << " is present in the matrix." << endl;
    }
    else{
        cout << t << " is not present in the matrix." << endl;
    }
    return 0;
}