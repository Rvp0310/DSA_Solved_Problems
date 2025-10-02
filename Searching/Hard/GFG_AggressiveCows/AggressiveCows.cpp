/* 
Date: January 28, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/aggressive-cows)
-----------------------------------------------------------
Problem Statement: [originally a medium level problem]
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.
-----------------------------------------------------------
Approach:
Sort the stall positions in ascending order to make distance comparisons meaningful. Apply binary search on the possible minimum distance between any two cows (search space: [1, max distance]). At each midpoint, greedily place cows: start with the first stall, and for every next stall, place a cow only if it's at least `mid` units away from the last placed cow. If it's possible to place all cows this way, the distance is feasible—try to maximize it. Otherwise, reduce the distance. The maximum feasible minimum distance is returned as the result.
-----------------------------------------------------------
Time Complexity: O(log (min(a, b)))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool check(vector<int> &arr, int d, int len, int key){
        int count = 1, last_stall = arr[0];
        for(int i = 1; i < len; i++){
            if(arr[i] - last_stall >= d){
                count++;
                last_stall=arr[i];
            }
            if(count >= key){
                return true;
            }
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k){
        sort(stalls.begin(), stalls.end());
        int n = stalls.size(), l = 1, r = stalls[n - 1] - stalls[0] , result = 0;
        while(l <= r){
            int m = (l + r) / 2;
            if(check(stalls, m, n, k)){
                result = m;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return result;
    }
};

int main(){
    string input;
    cout << "Enter the locations of the sheds (separated by space):" << endl;
    getline(cin, input);
    stringstream ss(input);
    int num;
    vector<int> nums;
    while (ss >> num){
        nums.push_back(num);
    }
    int c;
    cout << "Enter the no.of aggressive cows:" << endl;
    cin >> c;
    Solution s;
    cout << "The minimum distance between the cows in this case is " << s.aggressiveCows(nums, c) << ", which is the largest among all possible ways." << endl;
    return 0;
}