/* 
Date: December 14, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/product-array-puzzle4525)
-----------------------------------------------------------
Problem Statement: 
Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
Note: Each element is res[] lies inside the 32-bit integer range. 
-----------------------------------------------------------
Approach:
The result array is built using prefix and suffix products without using extra space. First, a prefix product is maintained while moving from left to right, and for each index, the product of all elements before it is stored in the result array. Then, a suffix product is maintained while moving from right to left, and for each index, the product of all elements after it is multiplied with the already stored prefix value. After both passes, each position in the result array contains the product of all elements except the one at that index.
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

// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        
        int prefix = 1;
        for(int i = 0; i < n; i++){
            res[i] = prefix;
            prefix *= arr[i];
        }
        
        int suffix = 1;
        for(int i = n - 1; i >= 0; i--){
            res[i] *= suffix;
            suffix *= arr[i];
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

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;

    Solution s;
    vector<int> result = s.productExceptSelf(nums);

    cout << "Final Product Array:" << endl;
    for(int el: result){
        cout << el << endl;
    }
    
    return 0;
}