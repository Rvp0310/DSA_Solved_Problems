/* 
Date: May 28, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/find-unique-number)
-----------------------------------------------------------
Problem Statement:
Given a unsorted array arr[] of positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.
-----------------------------------------------------------
Approach:
Use the XOR operation to find the unique element. XOR all elements in the array. The result will be the unique element.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int n = arr.size(), res = 0;
        
        for(int a: arr){
            res ^= a;
        }
        
        return res;
    }
};

int main(){
    string input;
    cout << "Enter the array elements (seperated by spaces,such that only one unique, and rest are duplicates):" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nums;
    int num;

    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    Solution s;
   
    cout << "\nUnique Element: " << s.findUnique(nums) << endl;

    return 0;
}