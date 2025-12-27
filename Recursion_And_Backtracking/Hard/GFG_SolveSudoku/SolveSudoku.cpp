/* 
Date: December 27, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/solve-the-sudoku-1587115621)
-----------------------------------------------------------
Problem Statement:
Given an incomplete Sudoku in the form of matrix mat[][] of order 9*9, the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.
-----------------------------------------------------------
Approach:
Three helper arrays are maintained: row, col, and box. Each element in these arrays is an integer that works as a bitmask to track which digits (1–9) are already used in a particular row, column, or 3×3 sub-box.

At the start, the given Sudoku board is scanned once. For every non-zero cell, the corresponding bit for that number is set in its row, column, and box masks. This preprocessing allows constant-time checks later.

The recursive function processes the board cell by cell, moving left to right and top to bottom. If the current cell is already filled, recursion simply moves to the next cell. If the cell is empty, digits from 1 to 9 are tried one by one. Before placing a digit, a safety check is performed using bit masks to ensure the digit is not already present in the same row, column, or 3×3 box.

If a digit is safe, it is placed in the cell, and the corresponding bits are set in the row, column, and box masks. The function then recursively attempts to solve the rest of the board. If a dead end is reached, the placement is undone by resetting the cell to 0 and clearing the bits from the masks, which is the backtracking step. Since the problem guarantees exactly one solution, the recursion eventually fills the board completely and returns true.
-----------------------------------------------------------
Time Complexity: O(9 ^ (n * n))
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
  
    bool isSafe(vector<vector<int>> &mat, int num, int i, int j, vector<int> &row, vector<int> &col, vector<int> &box) {
        int mask = 1 << (num - 1);
        if((row[i] & mask) || (col[j] & mask) || (box[(i / 3) * 3 + (j / 3)] & mask)) {
            return false;
        }
        
        return true;
    }
  
    bool solveSudokuRec(vector<vector<int>> &mat, int i, int j, vector<int> &row, vector<int> &col, vector<int> &box) {
        int n = mat.size();
        
        if (i == n){
            return true;
        }
        
        if (j == n){
            return solveSudokuRec(mat, i + 1, 0, row, col, box);
        }
        
        if (mat[i][j] != 0){
            return solveSudokuRec(mat, i, j + 1, row, col, box);
        }
        
        for (int num = 1; num <= n; num++) {
            if(isSafe(mat, num, i, j, row, col, box)){
                mat[i][j] = num;
                int mask = 1 << (num - 1);
                row[i] |= mask;
                col[j] |= mask;
                box[(i / 3) * 3 + (j / 3)] |= mask;
                if(solveSudokuRec(mat, i, j + 1, row, col, box)){
                    return true;
                }
                mat[i][j] = 0;
                row[i] &= ~mask;
                col[j] &= ~mask;
                box[(i / 3) * 3 + (j / 3)] &= ~mask;
            }
        }
        
        return false;
    }
  
    bool solveSudoku(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<int> row(n, 0), col(n, 0), box(n, 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != 0){
                    int mask = 1 << (mat[i][j] - 1);
                    row[i] |= mask;
                    col[j] |= mask;
                    box[(i / 3) * 3 + (j / 3)] |= mask;
                }
            }
        }
        
        return solveSudokuRec(mat, 0, 0, row, col, box);
    }
};

int main(){
    vector<vector<int>> mat(9, vector<int>(9));

    cout << "Enter the elements of soduko [1 - 9] (0 for missing places):" << endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    bool ok = obj.solveSudoku(mat);
    if(!ok) {
        cout << "\nNo solution exists\n";
    } 
    else {
        cout << "\nSolved:\n" << endl;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}