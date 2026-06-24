/* 
Date: June 24, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1?page=1&category=prefix-sum&sortBy=submissions)
-----------------------------------------------------------
Problem Statement: 
Given an array arr and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.
-----------------------------------------------------------
Approach:
Count the number of elements less than or equal to k. This gives the required window size. Then use a sliding window of this size and count how many elements greater than k (bad elements) are present in each window. The minimum number of bad elements among all windows is the minimum number of swaps required.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size(), good = 0;
        
        for(int el: arr){
            if(el <= k){
                good++;
            }
        }
        
        int bad = 0, minSwap = good;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > k){
                bad++;
            }
            
            if(i == good - 1){
                minSwap = min(minSwap, bad);
            } else if (i >= good){
                if(arr[i - good] > k){
                    bad--;
                }
                
                minSwap = min(minSwap, bad);
            }
        }
        
        return minSwap;
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

    int k;
    cout << "Enter value of K:" << endl;
    cin >> k;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;

    cout << "Min Swaps required to bring all <= " << k << " elements together: " << s.minSwap(nums, k) << endl;
    
    return 0;
}