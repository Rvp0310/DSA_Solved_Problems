/* 
Date: December 9, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-in-array-whose-sum-is-closest-to-x1124)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a ≤ b whose sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.
-----------------------------------------------------------
Approach:
The array is sorted so pair checking becomes predictable. Two pointers are placed at the left and right ends, and their sum is compared to the target. For every sum, the absolute difference from the target is calculated, and if this difference is smaller than the best difference seen so far, the current pair becomes the new answer. After checking a pair, the pointer movement depends on whether the sum is above or below the target: a larger sum shifts the right pointer left, and a smaller sum shifts the left pointer right. This continues until the pointers cross, ensuring the closest-sum pair is identified.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if(n < 2){
            return {};
        }

        sort(arr.begin(), arr.end());
        
        vector<int> ans;
        int l = 0, r = n - 1, minDiff = INT_MAX;
        while (l < r) {
            int sum = arr[l] + arr[r];
            int diff = abs(target - sum);
            if(minDiff > diff){
                minDiff = diff;
                ans = {arr[l], arr[r]};
            }
            
            if(sum > target){
                r--;
            } else {
                l++;
            }
        }
        
        return ans;
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
    vector<int> result = s.sumClosest(nums, target);

    if(result.size() > 0){
        cout << "The pair with closest sum to " << target << " is:" << endl;
        for(int el: result){
            cout << el << endl;
        }
    } else {
        cout << "The pair with closest sum to " << target << " doesn't exist." << endl;
    }
    return 0;
}