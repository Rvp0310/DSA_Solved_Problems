/* 
Date: December 13, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/trapping-rain-water-1587115621)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
-----------------------------------------------------------
Approach:
Two pointers are used to scan the array from both ends while keeping track of the tallest block seen so far on each side. At every step, the side with the smaller maximum height is processed because it limits how much water can be stored there. The water trapped at the current index is calculated as the difference between that side’s maximum height and the current block height, if positive, and added to the result. Then the pointer on that side moves inward and the corresponding maximum height is updated. This continues until both pointers cross, ensuring all trapped water is counted in a single pass with constant extra space.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size(), res = 0;
        int l = 1, r = n - 2;
        int lMax = arr[l - 1], rMax = arr[r + 1];
        
        while(l <= r){
            if(lMax >= rMax){
                res += max(0, rMax - arr[r]);
                rMax = max(rMax, arr[r]);
                r--;
            } else {
                res += max(0, lMax - arr[l]);
                lMax = max(lMax, arr[l]);
                l++;
            }
        }
        return res;
    }
};

int main() {
    string input;
    cout << "Enter the array elements (separated by space):" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> nums;
    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    int result = s.maxWater(nums);

    cout << "Overall Water Contained: " << result << endl;

    return 0;
}