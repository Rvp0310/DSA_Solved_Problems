/* 
Date: November 26, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/second-largest3735)
-----------------------------------------------------------
Problem Statement:
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
Note: The second largest element should not be equal to the largest element.
-----------------------------------------------------------
Approach:
Traverse twice: first to find the maximum, second to find the largest element strictly less than it — a straightforward O(n) approach balancing clarity with performance.
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
    int getSecondLargest(vector<int> &arr) {
        int max=arr[0],secmax=-1,n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        for(int j=0;j<n;j++)
        {
            if(arr[j]<max&&arr[j]>secmax)
            {
                secmax=arr[j];
            }
        }
        return secmax;
    }
};

int main(){
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

    Solution s;
    cout << "\nThe Second Largest element of the given array is " << s.getSecondLargest(nums);
    
    return 0;
}