/* 
Date: February 2, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/spirally-traversing-a-matrix-1587115621)
-----------------------------------------------------------
Problem Statement: 
You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.
-----------------------------------------------------------
Approach:
Use 4 pointers: top, bottom, left, right to define current matrix bounds.
Traverse in spiral order: 
1. Left → Right (top row), then top++
2. Top ↓ Bottom (right col), then right--
3. Right → Left (bottom row, if valid), then bottom--
4. Bottom ↑ Top (left col, if valid), then left++
Repeat until all bounds are crossed.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        int n = mat.size(), m = mat[0].size(), top = 0, bottom = n - 1 , left = 0, right = m - 1;
        vector<int> res;
        while(top <= bottom && left <= right){
            for(int c1 = left; c1 <= right; c1++){
                res.push_back(mat[top][c1]);
            }
            top++;
            for(int r1 = top; r1 <= bottom; r1++){
                res.push_back(mat[r1][right]);
            }
            right--;
            if(top <= bottom){
                for(int c2 = right; c2 >= left; c2--){
                    res.push_back(mat[bottom][c2]);
                }
            }
            bottom--;
            if(left <= right){
                for(int r2 = bottom; r2 >= top; r2--){
                    res.push_back(mat[r2][left]);
                }
            }
            left++;
        }
        return res;
    }
};

int main(){
    int m, n;
    cout << "Enter the no.of rows in the matrix:" << endl;
    cin >> n;
    cout << "Enter the no.of columns in the matrix:" << endl;
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements of the matrix (row-wise):" << endl;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    cout << "Given Matrix:" << endl;
    for(const auto& row : matrix){
        for(int x : row) 
            cout << x << " ";
        cout << endl;
    }
    Solution s;
    vector<int> r = s.spirallyTraverse(matrix);
    cout << "The spiral traversal of this matrix gives: ";
    for (int x : r){
        cout << x <<", ";
    }
    return 0;
}