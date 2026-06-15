/* 
Date: June 15, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1?page=1&category=Recursion&sortBy=submissions)
-----------------------------------------------------------
Problem Statement:
You are given a grid[][] of size n*m, where every element is either 'O' or 'X'. You have to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.
-----------------------------------------------------------
Approach:
Any 'O' connected to the boundary cannot be surrounded, so start a DFS from all boundary 'O' cells and mark them as visited. After marking all safe 'O' cells, traverse the grid and replace every unvisited 'O' with 'X'. The visited 'O' cells remain unchanged.
-----------------------------------------------------------
Time Complexity: O(n * m)
Auxiliary Space: O(n * m)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
  bool isSafe(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
      int n = grid.size(), m = grid[0].size();
      if(r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] && grid[r][c] == 'O'){
          return true;
      }
      return false;
  }
  
  void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c){
    visited[r][c] = true;
    
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    
    grid[r][c] = '#';
    for(int i = 0; i < 4; i++){
        int row = r + dr[i], col = c + dc[i];
        if(isSafe(row, col, grid, visited)){
            dfs(grid, visited, row, col);
        }
    }
    grid[r][c] = 'O';
  }
  
    void fill(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        for(int j = 0; j < m; j++){
            if(!visited[0][j] && grid[0][j] == 'O'){
                dfs(grid, visited, 0, j);
            }
            if(!visited[n - 1][j] && grid[n - 1][j] == 'O'){
                dfs(grid, visited, n - 1, j);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(!visited[i][0] && grid[i][0] == 'O'){
                dfs(grid, visited, i, 0);
            }
            if(!visited[i][m - 1] && grid[i][m - 1] == 'O'){
                dfs(grid, visited, i, m - 1);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]=='O' && !visited[i][j]){
                    grid[i][j] = 'X';
                }
            }
        }
    }
};

int main() {

    cout << "Enter the dimensions (n, m) of grid (space separated):" << endl;
    int n, m;
    cin >> n >> m;

    cout << "Enter the grid layout (X and O):" << endl;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] != 'X' && mat[i][j] != 'O'){
                cout << "Invalid cell value" << endl;
                return 0;
            }
        }
    }

    cout << "\nGrid:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    Solution obj;
    cout << "Modified Grid:" << endl;
    obj.fill(mat);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
