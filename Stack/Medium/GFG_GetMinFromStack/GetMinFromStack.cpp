/* 
Date: February 10, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/get-minimum-element-from-stack)
-----------------------------------------------------------
Problem Statement:
Implement a class SpecialStack that supports following operations:

push(x) – Insert an integer x into the stack.
pop() – Remove the top element from the stack.
peek() – Return the top element from the stack. If the stack is empty, return -1.
getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
isEmpty() –  Return true if stack is empty, else false
There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call push(x)
2:  Call pop()
3: Call peek()
4: Call getMin()
5: Call isEmpty()
The driver code will process the queries, call the corresponding functions, and print the outputs of peek(), getMin(), isEmpty() operations.
You only need to implement the above five functions.
-----------------------------------------------------------
Approach:
Two stacks are used:
1. Main stack to store all elements.
2. Auxiliary stack to track the minimum element at every level.

Whenever an element is pushed, it is also pushed into the
min stack if it is smaller than or equal to the current minimum.
During pop, if the popped element equals the current minimum,
it is removed from the min stack as well.
-----------------------------------------------------------
Time Complexity: O(n)  [Push, Pop, Peek, getMin → O(1)]
Space Complexity: O(n)
*/

#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
private:
    stack<int> st;
    stack<int> min_st;

public:
    SpecialStack() {
        // Default constructor
    }

    void push(int x) {
        st.push(x);
        if (min_st.empty() || x <= min_st.top()) {
            min_st.push(x);
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }
        if (st.top() == min_st.top()) {
            min_st.pop();
        }
        st.pop();
    }

    int peek() {
        if (st.empty()) {
            return -1;
        }
        return st.top();
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {
        if (st.empty()) {
            return -1;
        }
        return min_st.top();
    }
};

int main() {
    SpecialStack s;

    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);

    cout << "Top element: " << s.peek() << endl;
    cout << "Minimum element: " << s.getMin() << endl;

    s.pop();
    cout << "After pop:" << endl;
    cout << "Top element: " << s.peek() << endl;
    cout << "Minimum element: " << s.getMin() << endl;

    return 0;
}