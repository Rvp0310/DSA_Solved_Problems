/* 
Date: April 3, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/rotten-oranges2536)
-----------------------------------------------------------
Problem Statement:
Given a matrix mat[][], where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges

Your task is to determine the minimum time required so that all the oranges become rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

Note: If it is impossible to rot every orange then simply return -1.
-----------------------------------------------------------
Approach:
All initially rotten oranges are treated as starting points and added to a queue, then a BFS is performed where each level represents one unit of time. From every rotten orange, its 4-directional neighbors are checked, and any fresh orange is turned rotten and pushed into the queue for the next round. A flag tracks whether any change happened in that level to increment time only when rotting actually spreads. This continues until no more oranges can be rotted, and finally the grid is checked—if any fresh orange still remains, return -1, otherwise return the total time taken.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
  
    bool isSafe(int x, int y, int n, int m){
        return (x >= 0 && x < n && y >= 0 && y < m);    
    }
    
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()){
            int s = q.size();
            bool changes = false;
            
            for(int i = 0; i < s; i++){
                auto [x, y] = q.front();
                q.pop();
                
                for(vector<int> dir: dirs){
                    int xn = x + dir[0], yn = y + dir[1];
                    if(isSafe(xn, yn, n, m) && mat[xn][yn] == 1){
                        mat[xn][yn] = 2;
                        q.push({xn, yn});
                        changes = true;
                    }
                }
            }
            
            if(changes){
                res++;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return res;
    }
};

int main() {
    vector<vector<int>> mat;

    cout << "Enter the matrix (0 for empty cell, 1 for fresh and 2 for rotten; enter after defining):" << endl;
    int row = 0;
    while(true) {
        string s;
        getline(cin, s);

        if(s == ""){
            break;
        }

        stringstream ss(s);
        int num;
        vector<int> nums;
        while(ss >> num){
            nums.push_back(num);
        }
        mat.push_back(nums);

        row++;
    }
    

    cout << "Adjacency Matrix:" << endl;
    for(int i = 0; i < mat.size(); i++){
        cout << i << ":\t";
        for(int n: mat[i]){
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    Solution s;
    int r = s.orangesRot(mat);

    if (r != -1){
        cout << "Time taken for all oranges to rot: " << r << endl;
    } else {
        cout << "Not all oranges will be rotten." << endl;
    }
    
    return 0;
}