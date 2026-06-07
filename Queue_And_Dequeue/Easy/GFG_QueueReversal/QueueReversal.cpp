/* 
Date: June 7, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/queue-reversal/1?)
-----------------------------------------------------------
Problem Statement: 
Given a queue q containing integer elements, your task is to reverse the queue.
-----------------------------------------------------------
Approach:
Push all queue elements into a stack and then insert them back into the queue. The LIFO property of the stack reverses the queue.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> st;
        
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
    }
};

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    string input;
    cout << "Enter the array elements (separated by space):" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    queue<int> nums;
    while(ss >> num){
        nums.push(num);
    }

    int w;
    cout << "Enter the window size:" << endl;
    cin >> w;

    cout << "Given Queue: " << endl;
    printQueue(nums);

    Solution s;
    s.reverseQueue(nums);

    cout << "Queue reversed" << endl;
    printQueue(nums);
    
    return 0;
}