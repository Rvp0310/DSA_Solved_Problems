/* 
Date: December 10, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-possible-triangles-1587115620)
-----------------------------------------------------------
Problem Statement: 
Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.
-----------------------------------------------------------
Approach:
The array is sorted so triangle checking becomes systematic. For every element chosen as the largest side, two pointers are placed at the start and just before that largest side. Their values are added. If this sum is greater than the largest side, all values between the two pointers can form valid triangles with that largest side, so the total count increases by the number of those possibilities, and the right pointer moves left to explore the next combination. If the sum is not greater, the left pointer moves right to increase the sum. This repeats for each possible largest side, ensuring every valid triangle is counted.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int count = 0, n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i = n - 1; i >= 2; i--){
            int l = 0, r = i - 1;                                                           
            while(l < r){
                int sum = arr[r] + arr[l];
                if(sum > arr[i]){
                    count += (r - l);
                    r--;
                } else {
                    l++;
                }
            }
        }
        
        return count;
    }
};


int main(){
    string input;
    cout << "Enter the length of sides (separated by space):" << endl;
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
    int result = s.countTriangles(nums);

    if(result == 0){
        cout << "No triangle can be formed with given side lengths." << endl;
    } else {
        cout << result << " Triangles can be formed with given side lengths." << endl;
    }
    
    return 0;
}