/* 
Date: June 16, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1?page=1&category=two-pointer-algorithm&sortBy=submissions)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] of integers and another integer target. You have to find all unique quadruples from the given array whose sum is equal to the given target.

Note: All the quadruples should be internally sorted, i.e for any quadruple [q1, q2, q3, q4] it should be : q1 ≤ q2 ≤ q3 ≤ q4.
-----------------------------------------------------------
Approach:
Store all node values in a min-heap and build a new linked list by repeatedly taking the smallest element from the heap.
-----------------------------------------------------------
Time Complexity: O(n ^ 3)
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
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        vector<vector<int>> res;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n - 3; i++){
            if(i > 0 && arr[i] == arr[i - 1]) continue;
            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && arr[j] == arr[j - 1]) continue;
                int reqSum = target - (arr[i] + arr[j]);
                int l = j + 1, r = n - 1;
                while(l < r){
                    int sum = arr[l] + arr[r];
                    if(reqSum == sum){
                        vector<int> a = {arr[i], arr[j], arr[l], arr[r]};
                        sort(a.begin(), a.end());
                        res.push_back(a);
                        l++;
                        r--;
                        while(arr[l] == arr[l - 1]){
                            l++;
                        }
                        while(arr[r] == arr[r + 1]){
                            r--;
                        }
                    } else if(sum > reqSum){
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        
        sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
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

    int target;
    cout << "Enter the target element:" << endl;
    cin >> target;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    vector<vector<int>> result = s.fourSum(nums, target);

    cout << "The quadruples with sum = " << target 
         << " is: " << endl;
    for(vector<int> q: result){
        for(int el: q){
            cout << el << "\t";
        }
        cout << endl;
    }

    return 0;
}