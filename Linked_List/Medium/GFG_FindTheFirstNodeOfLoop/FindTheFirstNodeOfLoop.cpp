/* 
Date: December 18, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/find-the-first-node-of-loop-in-linked-list--170645)
-----------------------------------------------------------
Problem Statement: 
You are given the head of a singly linked list. If a loop is present in the linked list then return the first node of the loop else return -1.

Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null, indicating there is no loop. Note that pos is not passed as a parameter.
-----------------------------------------------------------
Approach:
The list is traversed using two pointers moving at different speeds. If they ever point to the same node, a loop is confirmed.
To find where the loop begins, one pointer is reset to the head. Both pointers then move one step at a time.
When they meet again, that node marks the start of the loop.
If they don't meet, the list does not contain a loop.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

# include <iostream>

using namespace std;

class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};

class Solution {
  public:
    int cycleStart(Node* head) {
        if(head == NULL){
            return -1;
        }
        Node *slow = head, *fast = head;
        
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast){
                slow = head;
                
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                
                return slow -> data;
            }
        }
        
        return -1;
    }
};

int main(){
    Node *head = NULL;
    // Creating nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;    // remove for no loop condition

    head = n1;

    Solution s;
    int x = s.cycleStart(head);

    if(x == -1){
        cout << "No Loop in given Linked List." << endl;
    } else {
        cout << "Loop starts at node -> data: " << x << endl;
    }
    
    return 0;
}