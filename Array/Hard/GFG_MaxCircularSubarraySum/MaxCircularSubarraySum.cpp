/* 
Date: December 27, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/minimize-the-heights3351)
-----------------------------------------------------------
Problem Statement:
You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.
-----------------------------------------------------------
Approach:
Run Kadane’s algorithm twice in one pass — once to find the maximum subarray sum, and once (in inverted form) to find the minimum subarray sum.
The normal Kadane result gives the best non-circular answer.
For the circular case, the max sum is `totalSum − minSubarray`, which represents taking the prefix + suffix around the minimum segment.
Two edge checks keep the result valid:
* If all numbers are negative, return the Kadane maximum directly.
* If the minimum subarray equals the entire array, the circular case is invalid, so again return the normal maximum.
The final result is the larger of the non-circular and valid circular values, computed in O(n) time.
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
        int n = arr.size();
        int minsum = INT_MAX, maxsum = INT_MIN, currmax = 0, currmin = 0, total = 0;
        for(int i = 0; i < n; i++){
            total += arr[i];
            currmax = max(currmax + arr[i], arr[i]);
            currmin = min(currmin + arr[i], arr[i]);
            maxsum = max(currmax, maxsum);
            minsum = min(currmin, minsum);
        }
        
        if (maxsum < 0 || total == minsum){
            return maxsum;
        }
      
        int result = max(maxsum, (total - minsum));
        return result;
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
