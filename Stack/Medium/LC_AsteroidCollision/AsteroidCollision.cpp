/* 
Date: December 6, 2025
Platform: LeetCode (https://leetcode.com/problems/asteroid-collision/)
-----------------------------------------------------------
Problem Statement: 
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
-----------------------------------------------------------
Approach:
Use a vector as a stack to simulate collisions. Right-moving asteroids are pushed directly. When a left-moving asteroid arrives, we only compare it with the top of the stack if that asteroid is moving right — the only situation where a collision can happen. While this head-on condition holds, resolve the clash: smaller right-moving asteroids get popped, equal sizes destroy each other, and a larger right-moving asteroid stops the incoming one. If the incoming asteroid survives all collisions, we push it into the stack.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int el: asteroids) {
            bool alive = true;
            while (!res.empty() && alive && el < 0 && res.back() > 0) {
                if (res.back() == -el) {
                    res.pop_back();
                    alive = false;
                } else if (res.back() < -el) {
                    res.pop_back();
                } else {
                    alive = false;
                }
            }
            if (alive) {
                res.push_back(el);
            }
        }

        return res;
    }
};

int main(){
    string input;
    cout << "Enter the sizes of asteroids (separated by space):" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nums;
    int num;
   
    while(ss >> num){
        nums.push_back(num);
    }

    cout << "Given Values:" << endl;
    for(int num : nums){
        cout << num <<"\t";
    }
    cout << endl;

    Solution s;
    vector<int> arr = s.asteroidCollision(nums);
    cout << "Final List Of Asteroids:" << endl;
    for(int el: arr){
        cout << el << endl;
    }

    return 0;
}