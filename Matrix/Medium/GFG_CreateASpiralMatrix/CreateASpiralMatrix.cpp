/* 
Date: June 12, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/create-a-spiral-matrix-of-nm-size-from-given-array/1?page=7&category=Matrix&sortBy=submissions)
-----------------------------------------------------------
Problem Statement:
You are given two positive integers n and m, and an integer array arr[] containing total (n*m) elements. Return a 2D matrix of dimensions n x m by filling it in a clockwise spiral order using the elements from the given array.
-----------------------------------------------------------
Approach:
Use four boundaries (top, bottom, left, right) and fill the matrix in clockwise spiral order. After completing each side of the current layer, update the boundaries and continue until all array elements are inserted.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class Solution {
  public:
    vector<vector<int>> spiralFill(int n, int m, vector<int> &arr) {
        vector<vector<int>> mat(n, vector<int>(m));
        
        int top = 0, left = 0, bottom = n - 1, right = m - 1, idx = 0, s = arr.size();
        
        while(idx < s){
            for(int j = left; j <= right; j++){
                mat[top][j] = arr[idx++];
            }
            top++;
            
            for(int i = top; i <= bottom; i++){
                mat[i][right] = arr[idx++];
            }
            right--;
            
            if(top <= bottom){
                for(int j = right; j >= left; j--){
                    mat[bottom][j] = arr[idx++];
                }
                bottom--;
            }
            
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    mat[i][left] = arr[idx++];
                }
                left++;
            }
        }
        
        return mat;
    }
};


int main(){
    string input;
    cout << "Enter the array elements (separated by space)" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> nums;
    
    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    int r, n = nums.size();
    do{
        cout << "Enter no.of rows wanted such that it divides " << n << ":" << endl;
        cin >> r;

        if(n % r != 0){
            cout << "Invalid Value" << endl;
        }

    } while(n % r != 0);

    int c = n / r;

    Solution s;
    vector<vector<int>> res = s.spiralFill(r, c, nums);
    
    cout << "\nSpiral Matrix:" << endl;
    for(vector<int> row: res){
        for(int el: row){
            cout << el << "\t";
        }
        cout << endl;
    }

    return 0;
}