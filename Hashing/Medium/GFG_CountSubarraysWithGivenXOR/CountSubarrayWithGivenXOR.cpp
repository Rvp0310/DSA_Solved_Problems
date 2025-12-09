/* 
Date: December 7, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-subarray-with-given-xor)
-----------------------------------------------------------
Problem Statement: 
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.
-----------------------------------------------------------
Approach:
First, keep a rolling XOR as you move through the array and that value reflect everything seen so far. Then, every time this running XOR either directly matches the target or pairs with some earlier prefix XOR to produce the target, count those matches by checking a hashmap that remembers how often each prefix XOR has appeared. Finally, store the current XOR in the map before moving on so every future subarray can trace back to it and reveal all valid XOR-k segments in one clean sweep.
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
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> prefixXORs;
        int res = 0, curr = 0;
        for(int el: arr){
            curr ^= el;
            
            if(curr == k){
                res++;
            }
            
            if(prefixXORs.find(curr ^ k) != prefixXORs.end()){
                res += prefixXORs[curr ^ k];
            }
            
            prefixXORs[curr]++;
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

    int target;
    cout << "Enter the target element:" << endl;
    cin >> target;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    int result = s.subarrayXor(nums, target);

    cout << "The total number of pairs with XOR = " << target 
         << " is: " << result << endl;

    return 0;
}