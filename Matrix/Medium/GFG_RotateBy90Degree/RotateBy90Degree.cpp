/* 
Date: January 31, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/rotate-by-90-degree-1587115621)
-----------------------------------------------------------
Problem Statement: 
Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 
-----------------------------------------------------------
Approach:
Reverse each row of the matrix, then perform transposition to get 90 degree anti-clockwise rotation of given matrix.
-----------------------------------------------------------
Time Complexity: O(n ^ 2)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
};


int main(){
    int n;
    cout << "Enter the size of the square matrix (n x n):" << endl;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix (row-wise):" << endl;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    cout << "Given Matrix:" << endl;
    for (const auto& r : matrix){
        for (int el : r){
            cout << el << " ";
        }
        cout << endl;
    }
    Solution s;
    s.rotateby90(matrix);
    cout << "After 90 degree rotation:" << endl;
    for (const auto& r : matrix){
        for (int el : r){
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}
