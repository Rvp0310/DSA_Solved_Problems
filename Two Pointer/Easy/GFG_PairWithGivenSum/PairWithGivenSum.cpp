/* 
Date: December 9, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-with-given-sum-in-a-sorted-array4940)
-----------------------------------------------------------
Problem Statement: 
You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
Note: pairs should have elements of distinct indexes. 
-----------------------------------------------------------
Approach:
The array is already sorted, so two pointers are placed at the start and end to compare sums efficiently. When the two pointed values sum to the target, either all pairs are counted at once if both pointers sit on the same repeated value, or the number of duplicates on both sides is counted separately to compute how many pairs this match creates. If the current sum is larger than the target, the right pointer moves left; if the sum is smaller, the left pointer moves right. This continues until the pointers cross, ensuring every valid pair is included.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size(), count = 0;
        
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum == target) {
                if (arr[l] == arr[r]) {
                    int m = (r - l) + 1;
                    count += m * (m - 1) / 2;
                    break;
                } else {
                    int countL = 1, countR = 1;
                    while (l + 1 < r && arr[l] == arr[l + 1]) {
                        countL++;
                        l++;
                    }
                    while (r - 1 > l && arr[r] == arr[r - 1]) {
                        countR++;
                        r--;
                    }
                    count += (countL * countR);
                    l++;
                    r--;
                }
            } else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
        
        return count;
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
    int result = s.countPairs(nums, target);

    cout << "The total number of pairs with sum = " << target 
         << " is: " << result << endl;

    return 0;
}