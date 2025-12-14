/* 
Date: December 13, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/container-with-most-water0535)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.

Note: In the case of a single vertical line it will not be able to hold water.
-----------------------------------------------------------
Approach:
Two pointers are placed at the beginning and end of the array to form the widest possible container. At each step, the water that can be stored between these two lines is calculated using the product of distance between the pointers and the smaller of the two heights, and the maximum volume is updated if this value is larger. Then, the pointer pointing to the shorter line is moved inward because keeping it cannot increase the water level, while the taller line is kept in place. This process continues until the pointers meet, ensuring the maximum possible water container is found in linear time.
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
        int n = arr.size();
        int l = 0, r = n - 1;
        int max_vol = 0;
        while(l < r){
            int curr_vol = (r - l) * min(arr[r], arr[l]);
            max_vol = max(max_vol, curr_vol);
            if(arr[l] <= arr[r]){
                l++;
            } else {
                r--;
            }
        }
        return max_vol;
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

    cout << "Max Water Contained: " << result << endl;

    return 0;
}