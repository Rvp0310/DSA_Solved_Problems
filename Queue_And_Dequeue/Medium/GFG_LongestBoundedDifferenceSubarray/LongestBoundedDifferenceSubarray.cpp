/* 
Date: December 28, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/queue-and-deque-gfg-160/problem/longest-bounded-difference-subarray)
-----------------------------------------------------------
Problem Statement: 
Given an array of positive integers arr[] and a non-negative integer x, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than x.
If multiple such subarrays exist, return the one that starts at the smallest index.-----------------------------------------------------------
Approach:
This solution uses a sliding window technique along with two deques to efficiently track the minimum and maximum values in the current subarray. As the window expands by moving the `end` pointer, the `minQueue` maintains indices of elements in increasing order (so the front always gives the minimum), while the `maxQueue` maintains indices in decreasing order (so the front always gives the maximum). If at any point the difference between the maximum and minimum values in the window exceeds `x`, the window is shrunk from the left by moving the `start` pointer and removing outdated indices from the deques. Throughout the process, the code keeps updating the longest valid window found so far. Once the traversal is complete, the elements corresponding to the longest valid subarray are extracted and returned. This approach runs in linear time because each element is added and removed from the deques at most once.
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
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> minQueue, maxQueue;
        
        int start = 0, end = 0, resStart = 0, resEnd = 0, n = arr.size();
        
        while(end < n){
            while(!minQueue.empty() && arr[minQueue.back()] > arr[end]) {
                minQueue.pop_back();
            }
            
            while(!maxQueue.empty() && arr[maxQueue.back()] < arr[end]) {
                maxQueue.pop_back();
            }
            
            maxQueue.push_back(end);
            minQueue.push_back(end);
            
            while((arr[maxQueue.front()] - arr[minQueue.front()]) > x) {
                if(start == minQueue.front()){
                    minQueue.pop_front();
                }
                if(start == maxQueue.front()){
                    maxQueue.pop_front();
                }
                start++;
            }
            
            if((end - start) > (resEnd - resStart)){
                resEnd = end;
                resStart = start;
            }
            
            end++;
        }
        
        vector<int> res;
        for(int i = resStart; i <= resEnd; i++){
            res.push_back(arr[i]);
        }
        
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

    int diff;
    cout << "Enter the difference permitted:" << endl;
    cin >> diff;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    vector<int> result = s.longestSubarray(nums, diff);

    cout << "Largest Subarray from given:" << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "\t";
    }
    
    return 0;
}