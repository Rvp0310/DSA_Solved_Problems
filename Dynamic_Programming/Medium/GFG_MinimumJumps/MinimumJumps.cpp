/* 
Date: March 16, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/minimum-number-of-jumps-1587115620)
-----------------------------------------------------------
Problem Statement:
You are given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.

For example:

If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.

Note:  Return -1 if you can't reach the end of the array.
-----------------------------------------------------------
Approach:
Keeping track of the farthest reachable index at each step and the current range of the jump. Starting from the first index, the farthest position reachable (maxReach) is updated at each index based on the maximum jump from that position. When the current index reaches the end of the current jump range (currReach), a jump is counted and the range is extended to maxReach. If at any point the current index equals maxReach, it indicates that forward progress is blocked, so the end cannot be reached. The process continues until the last index is within reach, and the total number of jumps taken is returned as the minimum required.
-----------------------------------------------------------
Time Complexity: O(n * sum)
Space Complexity: O(sum)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <climits>

using namespace std;

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), currReach = 0, maxReach = 0, jump = 0;
        
        if(n == 0 || arr[0] == 0){
            return -1;
        }

        for(int i = 0; i < n; i++){
            maxReach = max(maxReach, i + arr[i]);
            if(maxReach >= n - 1){
                return jump + 1;
            }
            
            if(i == currReach){
                if (i == maxReach){
                   return -1;
                } else {
                    jump++;
                    currReach = maxReach;
                }
            }
        }
        
        return -1;
    }
};


int main(){
    string s;
    cout << "Enter steps (space separated):" << endl;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> nums;

    while(ss >> num){
        nums.push_back(num);
    }

    Solution sol;
    cout << "Min Ways To Reach The Top: " << sol.minJumps(nums) << endl;
    return 0;
}