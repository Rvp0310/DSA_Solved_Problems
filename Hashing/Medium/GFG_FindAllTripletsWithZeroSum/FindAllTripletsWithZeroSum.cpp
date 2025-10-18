/* 
Date: October 17, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/find-all-triplets-with-zero-sum)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
Returned triplet should also be internally sorted i.e. i<j<k.
-----------------------------------------------------------
Approach:
The function finds all unique triplets of indices in an array whose elements sum to zero. An unordered_map is used to map each element to its index for O(1) access. Another unordered_map now stores all pairs of indices for the negative sum of every element pair, allowing the function to handle cases where multiple pairs produce the same sum. An unordered_set containing all elements from the given array is used to quickly check if the third element exists. A set<vector<int>> stores the triplets in sorted order, automatically removing duplicates. This ensures that even for duplicate elements or multiple same-sum pairs, all valid triplets are captured. Finally, the unique triplets are collected from the set and returned as a vector.
-----------------------------------------------------------
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        set<vector<int>> uniq;
        unordered_set<int> lookup(arr.begin(), arr.end());
        unordered_map<int, vector<pair<int, int>>> pairSum;
        unordered_map<int, int> indices;

        int n = arr.size();

        for(int i = 0; i < n; i++){
            indices[arr[i]] = i;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (i == j){
                    continue;
                }
                pairSum[-(arr[i] + arr[j])].push_back({i, j});
            }
        }

        for(auto& [sum, pairs] : pairSum){
            if(lookup.count(sum)){
                int k = indices[sum];
                for(auto& [i, j] : pairs){
                    if(i != k && j != k){
                        vector<int> triplet = {i, j, k};
                        sort(triplet.begin(), triplet.end());
                        uniq.insert(triplet);
                    }
                }
            }
        }

        vector<vector<int>> r(uniq.begin(), uniq.end());

        return r;
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

    cout << "\nTriplets with zero sums are:" << endl;
    Solution s;
    vector<vector<int>> r = s.findTriplets(nums);
    for(auto& vec : r){
        for(auto& i : vec){
            cout << "\t" << i;
        }
        cout << endl;
    }

    return 0;
}
