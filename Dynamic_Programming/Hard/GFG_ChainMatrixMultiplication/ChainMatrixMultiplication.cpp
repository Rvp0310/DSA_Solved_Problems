/* 
Date: March 26, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/matrix-chain-multiplication0303)
-----------------------------------------------------------
Problem Statement:
Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
-----------------------------------------------------------
Approach:
The idea is to decide the best place to split the chain of matrices so that total multiplication cost is minimum. Since multiplying matrices is associative, different parenthesizations give different costs, so every possible split between `i` and `j` is tried. A DP table `dp[i][j]` is used to store the minimum cost to multiply matrices from index `i` to `j`. The computation is done in increasing chain length (`len`), so smaller subproblems are solved first. For each pair `(i, j)`, every possible split point `k` is considered, and the cost is calculated as the cost of left part `dp[i][k]`, plus right part `dp[k][j]`, plus the cost of multiplying the resulting two matrices which is `arr[i] * arr[k] * arr[j]`. The minimum over all such splits is stored in `dp[i][j]`. Finally, `dp[0][n-1]` gives the minimum number of multiplications needed for the full chain.
-----------------------------------------------------------
Time Complexity: O(n ^ 3)
Space Complexity: O(n ^ 2)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int len = 2; len < n; len++){
            for(int i = 0; i < n - len; i++){
                int j = i + len;
                dp[i][j] = INT_MAX;
                
                for(int k = i + 1; k < j ; k++){
                    int cost = dp[i][k] + dp[k][j] + (arr[i] * arr[j] * arr[k]);
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

int main(){
    string s;
    cout << "Enter the dimensions of matrices (space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> nums;

    while(ss >> num){
        nums.push_back(num);
    }

    Solution sol;
    cout << " Min Mutliplications required: " << sol.matrixMultiplication(nums) << endl;

    return 0;
}