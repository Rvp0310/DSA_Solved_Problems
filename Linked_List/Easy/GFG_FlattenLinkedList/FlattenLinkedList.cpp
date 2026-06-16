/*
Date: June 16, 2026
Platform: GFG (https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1)
-----------------------------------------------------------
Problem Statement:
Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom points to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note:
1. ↓ represents the bottom pointer and → represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.
-----------------------------------------------------------
Approach:
Traverse all linked lists using the next and bottom pointers and insert every node value into a min-heap. Then repeatedly remove the smallest element from the heap and create a new flattened linked list using the bottom pointer.
-----------------------------------------------------------
Time Complexity: O(n * n * m)
Auxiliary Space: O(n)
*/

/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

void printBottomList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}


class Solution {
  public:
    Node *flatten(Node *root) {
        priority_queue<int, vector<int>, greater<>> pq;
        
        Node* curr = root;
        
        while(curr != nullptr){
            pq.push(curr -> data);
            Node* b = curr -> bottom;
            while(b != nullptr){
                pq.push(b -> data);
                b = b -> bottom;
            }
            curr = curr -> next;
        }
        
        Node* head = new Node(pq.top());
        pq.pop();
        Node* tail = head;
        while(!pq.empty()){
            Node* next = new Node(pq.top());
            pq.pop();
            tail -> bottom = next;
            tail = tail -> bottom;
        }
        
        return head;
    }
};

int main() {
    Node* head = new Node(5);

    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    // 5 -> 7 -> 8 -> 30
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    // 10 -> 20
    head->next->bottom = new Node(20);

    // 19 -> 22 -> 50
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    // 28 -> 35 -> 40 -> 45
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution obj;

    Node* flat = obj.flatten(head);

    cout << "Flattened List: ";
    printBottomList(flat);

    return 0;
}