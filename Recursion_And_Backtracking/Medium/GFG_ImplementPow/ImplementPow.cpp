/* 
Date: December 22, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/powx-n)
-----------------------------------------------------------
Problem Statement:
Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).
-----------------------------------------------------------
Approach:
First, handle the base case where the exponent is zero, since any number raised to the power zero equals one. If the exponent is negative, convert the problem into a positive exponent by taking the reciprocal of the base and making the exponent positive. The power is then calculated using recursion with fast exponentiation: the exponent is divided by two at each step, and the result of the smaller subproblem is reused. If the exponent is even, the result is obtained by squaring the half power, and if it is odd, the base is multiplied once more with the squared half power. This reduces the number of recursive calls and efficiently computes the result.
-----------------------------------------------------------
Time Complexity: O(n! * n)
Space Complexity: O(n)
*/

#include <iostream>

using namespace std;

class Solution {
  public:
    double power(double b, int e) {
        if (e == 0) {
            return 1;
        }
        
        long long exp = e;
        
        if (exp < 0) {
            b = 1 / b;
            exp = -exp;
        }
        
        return fastPow(b, exp);
    }
    
    double fastPow(double b, long long e) {
        if (e == 0) {
            return 1;
        }
        
        double half = fastPow(b, e / 2);
        
        if (e % 2 == 0) {
            return half * half;
        } else {
            return b * half *half;
        }
    }
};

int main () {
    int base, power;
    cout << "Enter the base value:" << endl;
    cin >> base;
    cout << "Enter the power value:" << endl;
    cin >> power;

    Solution s;
    cout << "Result of " << base << " ^ " << power << " = " << s.power(base, power) << endl;
    return 0;
}