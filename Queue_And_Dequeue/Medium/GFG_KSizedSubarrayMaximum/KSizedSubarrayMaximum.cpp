/* 
Date: December 28, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/queue-and-deque-gfg-160/problem/maximum-of-all-subarrays-of-size-k3101)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] of positive integers and an integer k. You have to find the maximum value for each contiguous subarray of size k. Return an array of maximum values corresponding to each contiguous subarray.
-----------------------------------------------------------
Approach:
The problem is solved using a deque to efficiently keep track of useful elements in each window of size k. The deque stores indices of array elements in decreasing order of their values, so the front of the deque always represents the maximum element of the current window. First, the deque is built for the initial window by removing smaller elements from the back before inserting a new index. Then, for each new element as the window slides forward, the maximum of the previous window is added to the result, indices that fall out of the current window are removed from the front, and smaller elements are again removed from the back to maintain order. After processing all elements, the maximum of the last window is added. This ensures each element is pushed and popped at most once, giving linear time complexity.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        deque<int> dq(k);
        
        for(int i = 0; i < k; i++){
            while(!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        for(int i = k; i < arr.size(); i++){
            res.push_back(arr[dq.front()]);
            
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        res.push_back(arr[dq.front()]);
        
        return res;
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

    int w;
    cout << "Enter the window size:" << endl;
    cin >> w;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    vector<int> result = s.maxOfSubarrays(nums, w);

    cout << "Maximum element from each window:" << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "\t";
    }
    
    return 0;
}