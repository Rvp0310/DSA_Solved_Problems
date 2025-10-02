/* 
Date: February 7, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-pairs-with-given-sum--150253)
-----------------------------------------------------------
Problem Statement: 
You are given an array arr[] and an integer target. You have to count all pairs in the array such that their sum is equal to the given target.
-----------------------------------------------------------
Approach:
Go through the array and use a hashmap to remember the numbers already seen. 
For each element, check if the value needed to reach the target (target - current element) is already in the map. 
If it is, then add how many times that value has appeared to my count because each occurrence forms a valid pair. 
After checking, increase the count of the current element in the map and move on. 
This way the array is scanned only once, making the time complexity O(n) and the space complexity O(n).
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int count = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i < arr.size(); i++){
            int req = target - arr[i];
            if(freq.find(req) != freq.end()){
                count += freq[req];
            }
            freq[arr[i]]++;
        }
        return count;
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

    int target;
    cout << "Enter the target element:" << endl;
    cin >> target;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    int result = s.countPairs(nums, target);

    cout << "The total number of pairs with sum = " << target 
         << " is: " << result << endl;

    return 0;
}