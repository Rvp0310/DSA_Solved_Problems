/* 
Date: January 4, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/find-median-in-a-stream-1587115620)
-----------------------------------------------------------
Problem Statement:
Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

The median is defined as follows:

1. Odd number of elements: The median is the middle element when the current set of numbers is sorted.
2. Even number of elements: The median is the arithmetic mean (average) of the two middle elements when the current set of numbers is sorted.
-----------------------------------------------------------
Approach:
The approach maintains the median of a streaming sequence using two heaps: a max-heap for the left half of the numbers and a min-heap for the right half. Each incoming number is added to one of the heaps depending on whether it is less than or greater than the top of the max-heap. After insertion, the heaps are balanced so that the max-heap always has the same number of elements as the min-heap or one more. This ensures that the median can be determined in constant time: if the heaps are equal in size, the median is the average of the tops of both heaps; otherwise, it is the top of the max-heap.
-----------------------------------------------------------
Time Complexity: O(n log k)
Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> res; 
        
        priority_queue<int, vector<int>, greater<int>> right;
        priority_queue<int> left;
        
        for(int el: arr){
            if(left.empty() || left.top() >= el){
                left.push(el);
            } else {
                right.push(el);
            }
            
            if(left.size() > right.size() + 1){
                right.push(left.top());
                left.pop();
            } else if (right.size() > left.size()){
                left.push(right.top());
                right.pop();
            }
            
            if(left.size() == right.size()){
                res.push_back((left.top() + right.top()) * 0.5);
            } else {
                res.push_back(left.top());
            }
        }
        
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

    cout << "Given Array:" << endl;
    for(int num : nums){
        cout << num <<"\t";
    }
    
    Solution s;
    vector<double> r = s.getMedian(nums);

    cout << "Medians:" << endl;
    for(double el: r){
        cout << el << "\t";
    }

    return 0;
}
