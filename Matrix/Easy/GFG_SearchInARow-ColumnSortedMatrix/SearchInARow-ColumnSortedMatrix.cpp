/* 
Date: January 31, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-matrix17201720)
-----------------------------------------------------------
Problem Statement: 
Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.
-----------------------------------------------------------
Approach:
Start from the top-right corner of the matrix. At each step, compare the current element with x. 
If it matches, return true. If the current element is greater than x, move left (eliminate the column). 
If it’s smaller, move down (eliminate the row). Continue until the element is found or indices go out of bounds. 
This greedy stepwise elimination works because both rows and columns are sorted.
-----------------------------------------------------------
Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int m = mat[0].size(), n = mat.size(), top = 0, right = m - 1;
        while(top < n && right >= 0){
            int el = mat[top][right];
           if(el == x){
               return true;
           }
           else if(el > x){
               right--;
           }
           else{
               top++;
           }
        }
        return false;
    }
};

int main(){
    int n, m;
    cout << "Enter the no.of rows in the matrix:" << endl;
    cin >> n;
    cout << "Enter the no.of columns in the matrix:" << endl;
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements of the matrix (row-wise):" << endl;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    int t;
    cout << "Enter the element to search for:" << endl;
    cin >> t;
    cout << "Given Matrix:" << endl;
    for (const auto& r : matrix){
        for (int el : r){
            cout << el << " ";
        }
        cout << endl;
    }
    Solution s;
    if(s.matSearch(matrix, t)){
        cout << t << " is present in the matrix." << endl;
    }
    else{
        cout << t << " is not present in the matrix." << endl;
    }
    return 0;
}