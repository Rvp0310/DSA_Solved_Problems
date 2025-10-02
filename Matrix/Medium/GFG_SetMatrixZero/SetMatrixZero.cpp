/* 
Date: February 5, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-row-wise-sorted-matrix)
-----------------------------------------------------------
Problem Statement: 
You are given a 2D matrix mat[][] of size n x m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0.
-----------------------------------------------------------
Approach:
First, traverse the entire matrix and record which rows and columns contain at least one 0.
Then, make a second pass through the matrix: if a cell belongs to a row or column marked earlier, set that cell to 0.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size(), top = 0, right = m - 1;
        vector<bool> rows(n), cols(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(rows[r] == true || cols[c] == true){
                    mat[r][c] = 0;
                }
            }
        }
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
    cout << "\nOriginal Matrix:" << endl;
    for(const auto& row: matrix){
        for(int el: row){
            cout << el << " ";
        }
        cout << endl;
    }
    Solution s;
    s.setMatrixZeroes(matrix);
    cout << "\nModified Matrix:" << endl;
    for(const auto& row: matrix){
        for(int el: row){
            cout << el << " ";
        }
        cout << endl;
    }
}