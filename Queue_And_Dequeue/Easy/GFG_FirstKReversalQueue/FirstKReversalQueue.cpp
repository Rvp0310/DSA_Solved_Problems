/* 
Date: June 7, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?)
-----------------------------------------------------------
Problem Statement: 
Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

"If the size of queue is smaller than the given k , then return the original queue."
-----------------------------------------------------------
Approach:
Push the first k elements of the queue into a stack to reverse their order, then add them to a new queue followed by the remaining elements.
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
	queue<int> reverseFirstK(queue<int> q, int k) {
		int n = q.size();
		if (k > n) {
			return q;
		}
		stack<int> st;
		
		while (k > 0) {
			st.push(q.front());
			q.pop();
			k--;
		}
		
		queue<int> qu;
		while (!st.empty()) {
			qu.push(st.top());
			st.pop();
		}
		while (!q.empty()) {
			qu.push(q.front());
			q.pop();
		}
		
		return qu;
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
    queue<int> result = s.reverseFirstK(nums, w);

    cout << "First :" << w << "elements reversed" << endl;
    printQueue(result);
    
    return 0;
}