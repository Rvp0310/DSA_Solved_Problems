/* 
Date: March 6, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/count-ways-to-reach-the-nth-stair-1587115620)
-----------------------------------------------------------
Problem Statement:
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).
-----------------------------------------------------------
Approach:
To reach the nth stair, the person can arrive either from the (n−1)th stair by taking 1 step or from the (n−2)th stair by taking 2 steps. This means the total number of ways to reach stair n is the sum of the ways to reach the previous two stairs, i.e., ways(n) = ways(n−1) + ways(n−2). This recurrence is exactly the same pattern as the Fibonacci sequence, because each state depends only on the two previous states. The base cases are ways(0) = 1 and ways(1) = 1, since there is only one way to stand still at the bottom or take a single step. Instead of storing all intermediate values in a DP array, we optimize space by keeping only the last two computed values (prev1 and prev2) and iteratively updating them to compute the next value, which represents the number of ways to reach the current stair.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countWays(int n) {
        int prev1 = 1, prev2 = 1;
        
        int curr;
        
        for(int i = 2; i <= n; i++){
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        
        return prev2;
    }
};

int main(){
    int x;
    cout << "Enter No.of stairs:" << endl;
    cin >> x;

    Solution sol;
    cout << "No.of Ways to go upstairs: " << sol.countWays(x) << endl;
    return 0;
}