/* 
Date: February 10, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/decode-the-string2444)
-----------------------------------------------------------
Problem Statement:
Given an encoded string s, decode it by expanding the pattern k[substring], where the substring inside brackets is written k times. k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets. Return the final decoded string.

Note: The test cases are generated so that the length of the output string will never exceed 105 .
-----------------------------------------------------------
Approach:
A stack is used to decode the string iteratively.
All characters are pushed onto the stack until a closing
bracket ']' is encountered. At this point, characters are
popped to form the encoded substring until '[' is found.
Then the digits preceding '[' are extracted to determine
the repeat count. The substring is repeated accordingly
and pushed back onto the stack. This process continues
until the entire string is traversed. Finally, the stack
contents are combined to form the decoded string.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string decodedString(string &s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                string temp;

                while (!st.empty() && st.top() != '[') {
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                st.pop(); // remove '['

                string num;
                while (!st.empty() && isdigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }

                int n = stoi(num);
                string repeated;

                while (n--) {
                    repeated.append(temp);
                }

                for (char c : repeated) {
                    st.push(c);
                }
            }
        }

        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};

int main() {
    Solution obj;
    string input;

    cout << "Enter encoded string:" << endl;
    getline(cin, input);

    string result = obj.decodedString(input);

    cout << "Decoded string: " << result << endl;

    return 0;
}