/* 
Date: April 4, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/find-the-number-of-islands)
-----------------------------------------------------------
Problem Statement:
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
-----------------------------------------------------------
Approach:
Traverse the grid cell by cell and whenever an unvisited land cell ('L') is found, start a DFS from that cell to mark the entire connected land as visited by exploring all 8 possible directions. Each DFS call effectively “consumes” one full island so it isn’t counted again. Every time such a new DFS is triggered, increment the island count. Continue this process for the whole grid, and the final count gives the total number of islands.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
  public:
  
    bool isSafe(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited){
        int n = grid.size(), m = grid[0].size();
        
        return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 'L' && !visited[x][y]);
    }
  
    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited){
        visited[x][y] = true;
        
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        
        for(auto [r, c]: dirs){
            int nr = x + r, nc = y + c;
            if(isSafe(grid, nr, nc, visited)){
                dfs(grid, nr, nc, visited);
            }
        }
    }
    
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'L' && !visited[i][j]){
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> mat;

    cout << "Enter the matrix ('L' for land and 'W' for water enter after defining):" << endl;
    int row = 0;
    while(true) {
        string s;
        getline(cin, s);

        if(s == ""){
            break;
        }

        stringstream ss(s);
        char c;
        vector<char> r;
        while(ss >> c){
            r.push_back(c);
        }
        mat.push_back(r);

        row++;
    }
    

    cout << "Area Grid:" << endl;
    for(int i = 0; i < mat.size(); i++){
        cout << i << ":\t";
        for(char n: mat[i]){
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    Solution s;
    int res = s.countIslands(mat);

    cout << "No.of Islands in Area: " << res << endl;
    
    return 0;
}