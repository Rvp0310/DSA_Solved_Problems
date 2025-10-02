/* 
Date: February 7, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/union-of-two-arrays3538)
-----------------------------------------------------------
Problem Statement: 
You are given two arrays a[] and b[], return the Union of both the arrays in any order.

The Union of two arrays is a collection of all distinct elements present in either of the arrays. If an element appears more than once in one or both arrays, it should be included only once in the result.

Note: Elements of a[] and b[] are not necessarily distinct.
Note that, You can return the Union in any order but the driver code will print the result in sorted order only.
-----------------------------------------------------------
Approach:
Inserted all elements of the first array into a set to store unique values, then iterated through the second array and added elements only if they were not already present in the set. Finally, returned the size of the set as the total number of unique elements in the union of the two arrays.
-----------------------------------------------------------
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> SetA (a.begin(), a.end());
        for(int i = 0; i < b.size(); i++){
            if(SetA.find(b[i]) == SetA.end()){
                SetA.insert(b[i]);
            }
        }
        return SetA.size();
    }
};

int main(){
    string input1, input2;
    cout << "Enter the first array elements (separated by space):" << endl;
    getline(cin, input1);

    cout << "Enter the second array elements (separated by space):" << endl;
    getline(cin, input2);

    stringstream ss1(input1), ss2(input2);
    int num;
    vector<int> a, b;

    while(ss1 >> num){
        a.push_back(num);
    }
    while(ss2 >> num){
        b.push_back(num);
    }

    cout << "First Array:" << endl;
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << "\t";
    }

    cout << "\nSecond Array:" << endl;
    for(int i = 0; i < b.size(); i++){
        cout << b[i] << "\t";
    }

    Solution s;
    int unionSize = s.findUnion(a, b);

    cout << "\nSize of Union of both arrays: " << unionSize << endl;

    return 0;
}