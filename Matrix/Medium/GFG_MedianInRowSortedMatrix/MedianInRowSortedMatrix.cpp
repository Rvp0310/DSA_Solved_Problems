/* 
Date: June 12, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?page=1&category=Matrix&sortBy=submissions)
-----------------------------------------------------------
Problem Statement: 
Given a row-wise sorted matrix (each row sorted independentally) mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.
-----------------------------------------------------------
Approach:
Use binary search on the answer. For each candidate value, count the number of elements less than or equal to it using upper_bound in every row. Based on the count, adjust the search range until the median value is found.
-----------------------------------------------------------
Time Complexity: O(n log m * log(maxVal – minVal))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        
        int minVal = INT_MAX, maxVal = INT_MIN;
        
        for(int i = 0; i < n; i++){
            if(minVal > mat[i][0]){
                minVal = mat[i][0];
            }
            if(maxVal < mat[i][m - 1]){
                maxVal = mat[i][m - 1];
            }
        }
        
        int desired = (n * m + 1) / 2;
        
        int lo = minVal, hi = maxVal;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            
            int count = 0;
            for(int i = 0; i < n; i++){
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if(count < desired){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
};


int main() {
    int n, m;
    cout << "Enter the size of the square matrix (n x m, space separated): ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter the elements row-wise and each row sorted:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    for(const auto& row : mat){
        for(int x : row) 
            cout << x << " ";
        cout << "\n";
    }

    Solution s;
    int med = s.median(mat);

    cout << "Median in given array: " << med << endl;
    return 0;
}