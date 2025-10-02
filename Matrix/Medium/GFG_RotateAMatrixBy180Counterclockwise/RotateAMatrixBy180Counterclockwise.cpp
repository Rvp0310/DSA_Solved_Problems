/* 
Date: July 31, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-bonus-problem/problem/c-matrix-rotation-by-180-degree0745)
-----------------------------------------------------------
Problem Statement: 
Given a 2D square matrix mat[][] of size n x n, rotate it by 180 degrees without using extra space.
Note: You must rotate the matrix in place and modify the input matrix directly.
-----------------------------------------------------------
Approach:
First reverse every row to simulate horizontal flipping. 
Then swap rows from top to bottom to complete the 180° rotation.
-----------------------------------------------------------
Time Complexity: O(n^(2))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        for(int j = 0; j <n/2; j++){
            swap(mat[j], mat[n - j - 1]);
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the square matrix (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter the elements row-wise:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> mat[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    for(const auto& row : mat){
        for(int x : row) 
            cout << x << " ";
        cout << "\n";
    }

    Solution s;
    s.rotateMatrix(mat);

    cout << "\nMatrix after 180° rotation:\n";
    for(const auto& row : mat){
        for(int x : row) 
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}