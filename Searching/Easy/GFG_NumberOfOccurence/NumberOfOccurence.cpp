/* 
Date: January 24, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/number-of-occurrence2259)
-----------------------------------------------------------
Problem Statement:
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 
-----------------------------------------------------------
Approach:
Since the array is sorted, iterate through it. Count occurrences of target until you either finish the array or reach a number greater than target, then break.
-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int count = 0;
        for(int i = 0; i< arr.size(); i++){
            if(arr[i] == target){
                count++;
            }
            else if(arr[i]>target){
                break;
            }
        }
        return count;
    }
};

int main(){
    string input;
    cout << "Enter the array elements (separated by space)" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> nums;
    
    while(ss >> num){
        nums.push_back(num);
    }

    int t;
    cout << "Enter the target value:" <<endl;
    cin >> t;

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    Solution s;
    cout << "\nTarget " << t << " appears " << s.countFreq(nums, t) << " times." << endl; 
}