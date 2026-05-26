/* 
Date: May 26, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/circular-tour-1587115620)
-----------------------------------------------------------
Problem Statement:
There are n gas stations along a circular tour. You are given two integer arrays gas[] and cost[], where gas[i] is the amount of gas available at station i and cost[i] is the gas needed to travel from station i to station (i+1). You have a car with an unlimited gas tank and start with an empty tank at some station. Your task is to return the index of the starting station if it is possible to travel once around the circular route in a clockwise direction without running out of gas at any station; otherwise, return -1.

Note: If a solution exists, it is guaranteed to be unique.
-----------------------------------------------------------
Approach:
Traverse all petrol pumps while keeping track of current fuel balance and total fuel balance.
At each station, add gas[i] - cost[i] to both balances.

If current balance becomes negative, it means the current starting point cannot complete the journey, so reset current balance to 0 and set the next station as the new starting point.

After traversing all stations:
    If total balance is negative, completing the circuit is impossible, return -1.
    Otherwise, the stored starting index is the answer.

The greedy idea is that whenever fuel becomes negative, every station before that point also becomes invalid as a starting station.
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
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size(), start = 0, curr = 0, total = 0;
        
        for(int i = 0; i < n; i++){
            curr += gas[i] - cost[i];
            total += gas[i] - cost[i];
            
            if(curr < 0){
                curr = 0;
                start = i + 1;
            }
        }
        
        if(total < 0){
            return -1;
        }
        
        return start;
    }
};

int main(){
    string input;
    cout << "Enter the gas values:" << endl;
    getline(cin, input);

    stringstream s1(input);
    vector<int> gas;
    int num;

    while(s1 >> num){
        gas.push_back(num);
    }

    cout << "Enter the cost values:" << endl;
    getline(cin, input);

    stringstream s2(input);
    vector<int> cost;

    while(s2 >> num){
        cost.push_back(num);
    }

    cout << "Gas - Cost:" <<endl;
    for(int i = 0; i < gas.size(); i++){
        cout << gas[i] << "\t" << cost[i] << endl;
    }

    Solution s;
    cout << "\nStarting station index: " << s.startStation(gas, cost) << endl;

    return 0;

}
