/* 
Date: December 31, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/implement-atoi)
-----------------------------------------------------------
Problem Statement:
Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.
Cases for atoi() conversion:
Skip any leading whitespaces.
Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
If the integer is greater than 2^(31) – 1, then return 2^(31) – 1 and if the integer is smaller than -2^(31), then return -2^(31).
-----------------------------------------------------------
Approach:
First skip all the leading spaces to get to the actual number. Then check if there’s a + or - to set the sign, no presence of sign defaults to +. After that, loop through every digit, converting it to a number and building the result one digit at a time. While doing that, also make sure it doesn’t overflow — if it does, just return INT_MAX or INT_MIN depending on the sign.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

class Solution {
    public:
        int myAtoi(char *s) {
            int sign = 1, result = 0, in = 0;
            while(s[in] == ' '){
                in++;
            }
            if(s[in] == '-' || s[in] == '+'){
                if(s[in] == '-'){
                    sign = -sign;
                    in++;
                }
            }
            while(s[in] >= '0' && s[in] <= '9'){            
                if(result > INT_MAX / 10|| (result == INT_MAX / 10 && s [in] - '0' > 7))
                {
                    return sign==1?INT_MAX:INT_MIN;
                }
                result = (result*10) + (s[in] - '0');
                in++;
            }
            return (result * sign);
        }
};

int main(){
    Solution s;
    string input;
    char str[50];
    cout << "Enter a number:" << endl;
    getline(cin, input);
    strncpy(str, input.c_str(), sizeof(str));
    int result = s.myAtoi(str);
    cout << "Converted integer: " << result << endl;
    return 0;
}