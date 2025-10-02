/* 
Date: December 21, 2024
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/majority-vote)
-----------------------------------------------------------
Problem Statement:
You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 
Note: The answer should be returned in an increasing format.
-----------------------------------------------------------
Approach:
If an element must appear more than ⌊n/3⌋ times to be a “majority,” then at most two elements can satisfy this in a single array — because three such elements would require more than n total slots, which is impossible.
This logic forms the backbone of the extended Boyer-Moore Voting Algorithm, where we track up to two candidates in first pass and verify them in a second pass.
-----------------------------------------------------------
Time Complexity: O(n)
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
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size(), count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] == candidate1){
                count1++;
            }
            else if (arr[i] == candidate2){
                count2++;
            }
            else if (count1 == 0){
                candidate1 = arr[i];
                count1++;
            }
            else if (count2 == 0){
                candidate2 = arr[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(int k = 0; k < n; k++){
            if (arr[k] == candidate1){
                count1++;
            }
            else if (arr[k] == candidate2){
                count2++;
            }
        }
        vector<int> results;
        if (count1 > n/3){
            results.push_back(candidate1);
        }
        if (count2 > n/3){
            results.push_back(candidate2);
        }
        if (results.size() == 2 && results[0] > results[1]){
            swap(results[0],results[1]);
        }
        return results;
    }
};

int main(){
    string input;
    cout << "Enter the choices:" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> choices;
    int num;

    while(ss >> num){
        choices.push_back(num);
    }

    cout << "Voter's Choices:" <<endl;
    for(int i = 0; i < choices.size(); i++){
        cout << choices[i] << "\t";
    }

    Solution s;
    vector<int> majority = s.findMajority(choices);

    cout << "\nThe Majority Votes:" << endl;
    for(int i = 0; i < majority.size(); i++){
        cout << majority[i] << "\t";
    }

    return 0;
}