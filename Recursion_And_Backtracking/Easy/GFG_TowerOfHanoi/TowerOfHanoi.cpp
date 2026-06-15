/* 
Date: June 15, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?page=1&category=Recursion&sortBy=submissions)
-----------------------------------------------------------
Problem Statement:
You are given n disks placed on a starting rod (from), with the smallest disk on top and the largest at the bottom. There are three rods: the starting rod(from), the target rod (to), and an auxiliary rod (aux).
You have to calculate the minimum number of moves required to transfer all n disks from the starting rod to the target rod, following these rules:
      1. Only one disk can be moved at a time.
      2. A disk can only be placed on top of a larger disk or on an empty rod.
Return the minimum number of moves needed to complete the task.
-----------------------------------------------------------
Approach:
To move n disks, first move the top n-1 disks from the source rod to the auxiliary rod. Then move the largest disk to the destination rod. Finally, move the n-1 disks from the auxiliary rod to the destination rod. Add the moves required in these three steps recursively.
-----------------------------------------------------------
Time Complexity: O(2^n)
Auxiliary Space: O(n)
*/

#include <iostream>

using namespace std;

class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n == 0){
        return 0;
      }
      
      return towerOfHanoi(n - 1, from, aux, to) + 1 + towerOfHanoi(n - 1, aux, to, from);
    }
};

int main(){
    int n;
    cout << "Enter number of disks:" << endl;
    cin >> n;

    Solution s;
    int result = s.towerOfHanoi(n, 1, 3, 2);

    cout << "The minimum no.of moves for " << n << " disks is: " << result << endl;

    return 0;
}