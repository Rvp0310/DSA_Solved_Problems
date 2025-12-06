/* 
Date: October 17, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/find-all-triplets-with-zero-sum)
-----------------------------------------------------------
Problem Statement: 
Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
Returned triplet should also be internally sorted i.e. i<j<k.
-----------------------------------------------------------
Approach:
Finds all unique index triplets whose values sum to zero by checking every pair (i, j), using a map for O(1) access to the required third element, and storing each sorted triplet in a set to automatically remove duplicates before returning the results.
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
        set<vector<int>> res;
        unordered_set<int> lookup(arr.begin(), arr.end());
        unordered_map<int, int> indices;

        int n = arr.size();

        for(int i = 0; i < n; i++){
            indices[arr[i]] = i;
        }

        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            int req = -(arr[i] + arr[j]);
            if(lookup.count(req)){
                int k = indices[req];
                if(i != k && j != k){
                    vector<int> tri = {i, j, k};
                    sort(tri.begin(), tri.end());
                    res.insert(tri);
                }
            }
        }
    }
    
    vector<vector<int>> r(res.begin(), res.end());

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

