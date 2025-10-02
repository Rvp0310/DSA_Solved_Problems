/* 
Date: February 7, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/intersection-of-two-arrays-with-duplicate-elements)
-----------------------------------------------------------
Problem Statement: 
Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. Intersection of two arrays is said to be elements that are common in both the arrays. The intersection should not have duplicate elements and the result should contain items in any order.
-----------------------------------------------------------
Approach:
Created a set from the first array to store its unique elements, then iterated through the second array and checked if each element was present in the set. If it was, added it to the result and erased it from the set to avoid duplicates, ensuring only one occurrence of each common element was included in the intersection.
-----------------------------------------------------------
Time Complexity: O(n + m)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_set<int> SetA (a.begin(), a.end());
        vector<int> res;
        for(int i = 0; i < b.size(); i++){
            if(SetA.find(b[i]) != SetA.end()){
                res.push_back(b[i]);
                SetA.erase(b[i]);
            }
        }
        return res;
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
    vector<int> res = s.intersectionWithDuplicates(a, b);

    cout << "\nIntersection (without duplicates):" << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << "\t";
    }
    cout << endl;

    return 0;
}