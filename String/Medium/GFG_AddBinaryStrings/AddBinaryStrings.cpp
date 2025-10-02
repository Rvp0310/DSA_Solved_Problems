/* 
Date: January 2, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/add-binary-strings3805)
-----------------------------------------------------------
Problem Statement:
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.
-----------------------------------------------------------
Approach:
Start by making sure the first string is longer. Then iterate from the end of both strings i.e Their LSB, adding corresponding bits along with a carry. Store the result bit and update the carry as needed. If the second/shorter string runs out, treat its bits as 0. After finishing, if there’s still a carry left, add it to the result. Finally, reverse the result string and remove any leading zeros before returning.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string addBinary(string& s1, string& s2){
            int n1 = s1.length(), n2 = s2.length();
            if (n1 < n2){
                return addBinary(s2, s1);
            }
            int j = n2 - 1, c = 0;
            string r = "";
            for (int i = n1 - 1; i >= 0; i--){
                int s = 0, a = s1[i] - '0', b = (j >=0 ? s2[j] - '0' : 0);
                s = (a + b + c) % 2;
                c = (a + b + c) / 2;
                j--;;
                r += s + '0';
            }
            if (c){
                r += '1';
            }
            reverse(r.begin(), r.end());
            int start = 0;
            while(r[start] == '0'){
                start++;
            }
            return r.substr(start);
        }
};

int main(){
    string s1, s2;
    cout << "Enter binary string 1:" << endl;
    getline(cin, s1);
    cout << "Enter binary string 2:" << endl;
    getline(cin, s2);
    Solution s;
    cout << "The sum of these binary strings is " << s.addBinary(s1, s2) << endl;
    return 0;
}