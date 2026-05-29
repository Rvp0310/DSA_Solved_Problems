/* 
Date: May 29, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/finding-the-numbers0215)
-----------------------------------------------------------
Problem Statement:
Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.
-----------------------------------------------------------
Approach:
First, XOR all elements of the array. Since duplicate numbers cancel each other out in XOR, the result will be the XOR of the two unique numbers. Then, find the rightmost set bit in this XOR value to identify a bit where the two unique numbers differ. Divide the array into two groups based on this bit and XOR elements of each group separately. Duplicate numbers cancel out again, leaving one unique number in each group. Finally, return the two numbers in increasing order.
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
    vector<int> singleNum(vector<int>& arr) {
        int val = 0;
        
        for(int a: arr){
            val ^= a;
        }
        
        val &= -val;
        
        vector<int> res(2);
        for(int a: arr){
            if((a & val) == 0){
                res[0] ^= a;
            } else {
                res[1] ^= a;
            }
        }
        
        if(res[1] < res[0]){
            int t = res[1];
            res[1] = res[0];
            res[0] = t;
        }
        
        return res;
    }
};

int main(){
    string input;
    cout << "Enter the array elements (seperated by spaces, such that only two are unique, and rest are duplicates):" << endl;
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
    vector<int> res = s.singleNum(nums);
   
    cout << "\nUnique Elements: " << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << "\t";
    }

    return 0;
}