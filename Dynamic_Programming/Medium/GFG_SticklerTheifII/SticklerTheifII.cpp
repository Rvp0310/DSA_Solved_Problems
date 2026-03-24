/* 
Date: March 24, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/house-robber-ii)
-----------------------------------------------------------
Problem Statement:
You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
Determine the maximum amount the thief can steal.

Note: Since the houses are in a circle, the first and last houses are also considered adjacent.
-----------------------------------------------------------
Approach:
Since the houses form a circle, the first and last houses cannot be robbed together. Because of this, the problem is split into two linear cases: rob houses from index 0 to n-2 (exclude last house) or rob houses from index 1 to n-1 (exclude first house). The helper function `maxVal(x, y, arr)` solves the normal house robber problem within that range by correctly initializing the first two states as `over = arr[x]` (best till first house in range) and `adj = max(arr[x], arr[x+1])` (best till second house, since both cannot be taken together). Then for each house `i`, `res = max(over + arr[i], adj)` decides whether robbing the current house (and adding it to the non-adjacent total) gives more profit or skipping it keeps the previous maximum. After processing the range, the function returns the maximum loot for that case, and the main function returns the maximum of the two cases to handle the circular restriction.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

class Solution {
  public:
  
    int maxVal(int x, int y, vector<int>& arr){
        int n = arr.size();
        
        if(n == 2){
            return max(arr[0], arr[1]);
        }
        
        int over = arr[x], adj = max(arr[x + 1], arr[x]);
        
        for(int i = x + 2; i <= y; i++){
            int res = max(over + arr[i], adj);
            
            over = adj;
            adj = res;
        }
        
        return adj;
    }
    
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 0){
            return 0;
        }
        
        if (n == 1){
            return arr[0];
        }
        
        int ans = 0;
        
        ans = max(ans, maxVal(0, n - 2, arr));
        ans = max(ans, maxVal(1, n - 1, arr));
        
        return ans;
    }
};

int main(){
    string s;
    cout << "Enter elements of array (space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> nums;

    while(ss >> num){
        nums.push_back(num);
    }

    Solution sol;
    cout << "Max Amount To Rob: " << sol.maxValue(nums) << endl;

    return 0;
}