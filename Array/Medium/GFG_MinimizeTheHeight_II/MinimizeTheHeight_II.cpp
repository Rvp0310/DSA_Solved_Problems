/* 
Date: December 24, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/minimize-the-heights3351)
-----------------------------------------------------------
Problem Statement:
Given an array arr[] denoting heights of N towers and a positive integer K.
For each tower, you must perform exactly one of the following operations exactly once.
Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.
You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.
-----------------------------------------------------------
Approach:
I first sorted the array, then checked each position to find the minimum possible difference between the tallest and shortest towers after increasing or decreasing each height by k, while skipping any case that would make a height negative.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n = arr.size(), mindiff = arr[n-1] - arr[0], minimum, maximum;
        for(int i = 1; i < n; i++)
        {
            if ((arr[i] - k) < 0)
            continue;
            maximum = max(arr[i - 1] + k, arr[n - 1] - k);
            minimum = min(arr[i] - k, arr[0] + k);
            mindiff= min(mindiff, maximum - minimum);
        }
        return mindiff;
    }
};

int main(){
    string input;
    cout << "Enter the heights of the tower (separated by space):" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> towers;
    int num;

    while(ss >> num){
        towers.push_back(num);
    }

    int k;
    cout << "Enter a value to modify the tower heights with:" << endl;
    cin >> k;

    cout << "Tower Heights:" <<endl;
    for(int i = 0; i < towers.size(); i++){
        cout << towers[i] << "\t";
    }

    Solution s;
    cout << "\nMinimum difference after operations with " << k << " is " << s.getMinDiff(towers, k) << endl;

    return 0;
}