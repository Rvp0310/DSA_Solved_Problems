/* 
Date: January 13, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/sort-an-array-of-0s-1s-and-2s4231)
-----------------------------------------------------------
Problem Statement:
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
You need to solve this problem without utilizing the built-in sort function.
-----------------------------------------------------------
Approach:
Count occurrences of 0s, 1s, and 2s in a single pass, then overwrite the array by placing the correct number of each in order.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int z = 0, o = 0, t = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                z++;
            }
            else if(arr[i] == 1){
                o++;
            }
            else{
                t++;
            }
        }
        int index = 0;
        while(index < z){
            arr[index++] = 0;
        }
        while(index < z + o){
            arr[index++] =1;
        }
        while(index < z + o + t){
            arr[index++] = 2;
        }
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

    cout << "Given Array:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    Solution s;
    s.sort012(nums);
    
    cout << "\nGiven Array after sorting:" << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    return 0;
}

