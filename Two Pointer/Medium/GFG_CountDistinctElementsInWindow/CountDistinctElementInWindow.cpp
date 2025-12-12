/* 
Date: December 12, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-distinct-elements-in-every-window)
-----------------------------------------------------------
Problem Statement: 
Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.
-----------------------------------------------------------
Approach:

-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        if(n < k){
            return {-1};
        }
        unordered_map<int, int> freq;
        vector<int> res;
        
        for(int i = 0; i < k; i++){
            freq[arr[i]]++;
        }
        res.push_back(freq.size());
        
        for(int i = k; i < n; i++){
            int out = arr[i - k];
            freq[out]--;
            if(freq[out] == 0){
                freq.erase(out);
            }
            
            int in = arr[i];
            freq[in]++;
            
            res.push_back(freq.size());
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

    int window;
    cout << "Enter the window size:" << endl;
    cin >> window;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    vector<int> result = s.countDistinct(nums, window);

    if(result[0] == -1){
        cout << "Array Length < Window Size" << endl;
    } else {
        cout << "No.of distinct elements in each Window of size " << window << " :" << endl;
        for(int el: result){
            cout << el << endl;
        }
    }
    
    return 0;
}