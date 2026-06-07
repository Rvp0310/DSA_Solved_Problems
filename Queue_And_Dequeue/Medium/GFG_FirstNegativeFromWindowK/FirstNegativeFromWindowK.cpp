/* 
Date: June 7, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1?)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.
-----------------------------------------------------------
Approach:

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
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> res;
        deque<int> w;
        
        for(int i = 0; i < k; i++){
            if(arr[i] < 0){
                w.push_back(i);
            }
        }
        
        for(int i = k; i < n; i++){
            w.empty() ? res.push_back(0) : res.push_back(arr[w.front()]);
            while(!w.empty() && w.front() <= i - k){
                w.pop_front();
            }
            
            if(arr[i] < 0){
                w.push_back(i);
            }
        }
        
        if(w.empty()){
            res.push_back(0);
        } else {
            res.push_back(arr[w.front()]);
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

    int w;
    cout << "Enter the window size:" << endl;
    cin >> w;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    vector<int> result = s.firstNegInt(nums, w);

    cout << "First Negative from each window:" << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "\t";
    }
    
    return 0;
}