/* 
Date: December 25, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/n-queen-problem0315)
-----------------------------------------------------------
Problem Statement: 
The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n].

In this representation, the number in the ith position denotes the column in which the queen is placed in the ith row.
For eg. below figure represents a chessboard [2, 4, 1, 3].
-----------------------------------------------------------
Approach:
The solution uses backtracking to place queens column by column while ensuring that no two queens attack each other. A queen is placed one column at a time, and for each column, all possible rows from 1 to n are tried. Before placing a queen at a given row and column, a safety check is performed to ensure that the row, left diagonal, and right diagonal are not already occupied by another queen. If a position is safe, the row number is added to the current board configuration and the algorithm moves to the next column recursively. If all columns are successfully filled, the current configuration represents a valid solution and is stored. After exploring a choice, the algorithm backtracks by removing the last placed queen and tries the next possible row. This process continues until all valid board configurations are generated.

To optimize safety checks, bitmasks are used instead of arrays. rowMask keeps track of which rows are already occupied. leftDiagMask tracks diagonals where row + col is constant, and rightDiagMask tracks diagonals where row - col is constant (+n to shift from negative range to positive). 
-----------------------------------------------------------
Time Complexity: O(n!)
Space Complexity: O(n ^ 2)
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
  public:
  
    bool isSafe(int row, int col, int n, int rowMask, int leftDiagMask, int rightDiagMask) {
        bool rowFree = ((rowMask >> row & 1) == 0);
        bool leftDiagFree = ((leftDiagMask >> (row + col) & 1) == 0);
        bool rightDiagFree = ((rightDiagMask >> (row - col + n) & 1) == 0);
        
        return rowFree && leftDiagFree && rightDiagFree;
    }
    
    void nQueenUtils(int col, int n, vector<vector<int>>& res, vector<int>& board, int rowMask, int leftDiagMask, int rightDiagMask) {
        if (col > n) {
            res.push_back(board);
            return;
        }
        
        for (int r = 1; r <= n; r++) {
            if (isSafe(r, col, n, rowMask, leftDiagMask, rightDiagMask)) {
                
                board.push_back(r);
                
                nQueenUtils(col + 1, n, res, board, (rowMask | (1 << r)), (leftDiagMask | (1 << (r + col))), (rightDiagMask | (1 << (r - col + n))));
                
                board.pop_back();
            }
        }
    }
  
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        
        vector<int> board;
        
        nQueenUtils(1, n, res, board, 0, 0, 0);
        
        return res;
    }
};

int main () {
    cout << "Enter no.of queens to place / sizde of chess board:" << endl;
    int n;
    cin >> n;
    Solution s;
    vector<vector<int>> r = s.nQueen(n);

    cout << "Possible Placements for " << n << " queens:" << endl;
    for (vector<int> conf: r) {
        for (int p: conf){
            cout << p << ", ";
        }
        cout << endl;
    }

    return 0;
}