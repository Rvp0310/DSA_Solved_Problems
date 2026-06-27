/* 
Date: June 27, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?page=1&category=Stack&sortBy=submissions)
-----------------------------------------------------------
Problem Statement: 
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.
-----------------------------------------------------------
Approach:
Use two pointers to eliminate people who cannot be the celebrity until only one candidate remains. Then verify that the candidate is known by everyone and does not know anyone. If both conditions hold, return the candidate; otherwise return -1.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        int i = 0, j = n - 1;
        
        while(i < j){
            if(mat[i][j] == 0){
                j--;
            } else {
                i++;
            }
        }
        
        int c = i;
        
        for(int i = 0; i < n; i++){
            if(i == c){
                continue;
            }
            
            if(mat[i][c] != 1 || mat[c][i] == 1){
                return -1;
            }
        }
        
        return c;
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
    int c = s.celebrity(matrix);
    if(c == -1){
        cout << "No Celebrity Detected" << endl;
    } else {
        cout << "Celebrity: " << c << endl;
    }
    return 0;
}
