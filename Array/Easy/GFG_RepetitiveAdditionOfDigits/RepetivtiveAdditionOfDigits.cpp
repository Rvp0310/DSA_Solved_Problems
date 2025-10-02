/* 
Date: January 06, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/repetitive-addition-of-digits2221)
-----------------------------------------------------------
Problem Statement:
You are given a positive integer n, you need to add all the digits of n and create a new number. Perform this operation until the resultant number has only one digit in it. Return the final number obtained after performing the given operation.
-----------------------------------------------------------
Approach:
First checked if the number is zero, in which case returned zero directly. Otherwise used the digital root property where a number and the sum of its digits leave the same remainder when divided by 9. This means n % 9 gives the same result as repeatedly adding digits. But for multiples of 9 this comes out as 0 while the digital root should be 9, so the formula is adjusted to 1 + (n - 1) % 9. The order of the digits doesn’t matter because powers of 10 reduce to 1 when divided by 9, so each digit just contributes its own value regardless of position, making the remainder depend only on the sum of digits.
-----------------------------------------------------------
Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <iostream>

using namespace std;

class Solution {
  public:
    int singleDigit(int n) {
        if(n==0){
            return 0;
        }
        return 1+(n-1)%9;
    }
};

int main(){
    int n;
    cout << "Enter a number:" << endl;
    cin >> n;

    Solution s;
    int result = s.singleDigit(n);

    cout << "The single digit sum of " << n << " is: " << result << endl;

    return 0;
}