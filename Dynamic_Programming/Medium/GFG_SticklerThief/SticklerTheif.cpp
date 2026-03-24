/* 
Date: March 24, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/stickler-theif-1587115621)
-----------------------------------------------------------
Problem Statement:
Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot.
Given an array, arr[] where arr[i] represents the amount of money in the i-th house. Determine the maximum amount he can loot.
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
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        
        int over = 0, adj = arr[0], r;
        
        for(int i = 1; i < n; i++){
            r = max(arr[i] + over, adj);
            over = adj;
            adj = r;
        }
        
        return r;
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
    cout << "Max Amount To Rob: " << sol.findMaxSum(nums) << endl;

    return 0;
}