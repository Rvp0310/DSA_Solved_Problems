/* 
Date: June 6, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1?page=4&sortBy=submissions)
-----------------------------------------------------------
Problem Statement:
Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.
-----------------------------------------------------------
Approach:
Use backtracking starting from cell (0, 0).
At every cell, try moving in all four possible directions:
'U' (up), 'D' (down), 'L' (left), and 'R' (right).
Before moving, check whether the next cell:
- lies inside the maze boundaries
- is not blocked
- has not been visited in the current path
To avoid revisiting a cell, mark the current cell as blocked (0) before exploring its neighbors. After all recursive calls finish, restore it back to 1 so that other paths can use it.
Whenever the destination cell (n-1, n-1) is reached, store the current path string in the result vector.
Finally, sort all collected paths to return them in lexicographical order.
-----------------------------------------------------------
Time Complexity: O(4 ^ (n * n))
Auxiliary Space: O(n * n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string dir = "UDLR";
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};

class Solution {
  public:
  
  bool isValid(int row, int col, int n, vector<vector<int>>& maze){
      if(row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1){
          return true;
      }
      return false;
  }
  
  void findPath (vector<vector<int>>& maze, vector<string>& res, string& path, int r, int c){
      int n = maze.size();
      
      if(r == n - 1 && c == n - 1){
          res.push_back(path);
          return;
      }
      
      maze[r][c] = 0;
      for(int i = 0; i < 4; i++){
          int row = r + dr[i], col = c + dc[i];
          if(isValid(row, col, n, maze)){
              path.push_back(dir[i]);
              findPath(maze, res, path, row, col);
              path.pop_back();
          }
      }
      maze[r][c] = 1;
  }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        
        vector<string> res;
        string path = "";
        
        if(maze[0][0] == 1 && maze[n - 1][n - 1] == 1){
            findPath(maze, res, path, 0, 0);
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};

int main() {

    cout << "Enter the dimension (n) of maze matrix (no.of row = no.of column):" << endl;
    int n;
    cin >> n;

    cout << "Enter the maze layout (0 for blocked cell and 1 for free cell):" << endl;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if(mat[i][j] != 0 && mat[i][j] != 1){
                cout << "Invalid cell value" << endl;
                return 0;
            }
        }
    }

    cout << "\nMaze:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    Solution obj;
    cout << "Paths from (0, 0) to (" << n - 1 << ", " << n - 1 << "):" << endl;
    vector<string> r = obj.ratInMaze(mat);
    for(string s: r){
        cout << s << endl;
    }

    return 0;
}
