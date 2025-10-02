/* 
Date: December 27, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/minimize-the-heights3351)
-----------------------------------------------------------
Problem Statement:
You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.
-----------------------------------------------------------
Approach:
Track normal max subarray sum (Kadane’s), and also min subarray sum to handle wrapping — final result is max of non-circular and circular (totalSum - minSubarray) for full coverage in O(n) time.
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
    int circularSubarraySum(vector<int> &arr) {
        int cmax,nmax=arr[0],currmax=arr[0],currmin=arr[0],nmin=arr[0],tsum=arr[0],n=arr.size();
        for(int i=1;i<n;i++){
            currmax=max(currmax+arr[i],arr[i]);
            nmax=max(currmax,nmax);
            currmin=min(currmin+arr[i],arr[i]);
            nmin=min(nmin,currmin);
            tsum+=arr[i];
        }
        cmax=max(tsum-nmin,nmax);
        return cmax;
    }
};

int main(){
    string input;
    cout << "Enter the elements of the array (separated by space):" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nums;
    int num;
   
    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given Array:" << endl;
    for(int num : nums){
        cout << num <<"\t";
    }
    
    Solution s;
    cout << "\nThe maximum subarray sum for the given array is " << s.circularSubarraySum(nums) << endl;

    return 0;
}