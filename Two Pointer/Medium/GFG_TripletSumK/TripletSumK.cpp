/* 
Date: December 8, 2025
Platform: LeetCode (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-all-triplets-with-given-sum-in-sorted-array)
-----------------------------------------------------------
Problem Statement: 
Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.
-----------------------------------------------------------
Approach:
Sort the array so comparing sums becomes predictable, then fix one element at index i and treat it as the first number of the triplet. Then, set two pointers l = i+1 and r = n-1 and check their sum against the remaining of required sum i.e target - i-th element, if their sum matches it, either count all combinations directly when both sides hold the same value or count how many duplicates appear on the left and right to know exactly how many triplets that match this case. Finally, if the sum is smaller than needed move the left pointer forward, if it’s larger move the right pointer back, and repeat this process for every i so every valid triplet is included.
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
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size(), count = 0;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n - 2; i++){
            int reqSum = target - arr[i];
            
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = arr[l] + arr[r];
                if (sum == reqSum){
                    if(arr[l] == arr[r]){
                        int m = (r - l) + 1;
                        count += m*(m-1) / 2;
                        break;
                    }
                    else {
                        int countL = 1, countR = 1;
                        while(l + 1 < r && arr[l + 1] == arr[l]){
                            countL++;
                            l++;
                        }
                        while(r - 1 > l && arr[r - 1] == arr[r]){
                            countR++;
                            r--;
                        }
                        count += (countL * countR);
                        l++;
                        r--;
                    }
                }
                else if (sum < reqSum){
                    l++;
                } else {
                    r--;
                }
            }
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
    int result = s.countTriplets(nums, target);

    cout << "The total number of triplets with sum = " << target 
         << " is: " << result << endl;

    return 0;
}