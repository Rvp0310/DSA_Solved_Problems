/* 
Date: January 4, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/article/MjM5Mg%3D%3D)
-----------------------------------------------------------
Problem Statement:
Given an array arr[] and an integer k, the task is to find k largest elements in the given array. Elements in the output array should be in decreasing order.
-----------------------------------------------------------
Approach:
The approach finds the k largest elements in an array using a min-heap of size k. First, the algorithm builds a min-heap with the first k elements of the array. Then, it iterates through the remaining elements, and whenever an element is larger than the root of the min-heap (which is the smallest among the current k largest), it replaces the root with this element and heapifies. This ensures that after processing the entire array, the min-heap contains the k largest elements. Finally, the elements are popped from the heap and reversed to produce a decreasing order output.
-----------------------------------------------------------
Time Complexity: O(k + (n-k) log k)
Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minH(arr.begin(), arr.begin() + k);
        
        for(int i = k; i < arr.size(); i++){
            if(arr[i] > minH.top()){
                minH.pop();
                minH.push(arr[i]);
            }
        }
        
        vector<int> res;
        while(!minH.empty()){
            res.push_back(minH.top());
            minH.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
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

    int k;
    cout << "Enter value of k:" << endl;
    cin >> k;

    cout << "Given Array:" << endl;
    for(int num : nums){
        cout << num <<"\t";
    }
    
    Solution s;
    vector<int> r = s.kLargest(nums, k);

    cout << endl;
    cout << k <<" Largest elements from given array are:" << endl;
    for(int el: r){
        cout << el << endl;
    }

    return 0;
}
