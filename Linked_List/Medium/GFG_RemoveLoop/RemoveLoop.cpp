/* 
Date: December 18, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/remove-loop-in-linked-list)
-----------------------------------------------------------
Problem Statement: 
Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.
-----------------------------------------------------------
Approach:
First, check whether the linked list is empty or contains only one node, because in both cases a loop cannot exist. Then use two pointers, slow and fast, where slow moves one step at a time and fast moves two steps at a time. Traverse the list using these pointers; if they ever meet, it confirms the presence of a loop, and if fast reaches NULL, no loop exists and no changes are needed. After detecting a loop, move slow back to the head of the list while keeping fast at the meeting point. If both pointers are already at the head, the loop starts from the first node, so move fast forward until fast->next points back to slow, placing fast at the last node of the loop. If the loop starts somewhere in the middle, move both slow and fast one step at a time until slow->next and fast->next point to the same node, which indicates the start of the loop and places fast at its last node. Finally, set fast->next to NULL to break the loop and restore the linked list to a proper linear form.
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

void printList(Node *node){
    while(node != nullptr) {
        cout << node -> data << " ";
        if(node -> next != NULL){
            cout << "-> ";
        } 
        node = node -> next;
    }
    cout << endl;
}

class Solution {
  public:
    void removeLoop(Node* head) {
        if(head == NULL || head -> next == NULL){
            return;
        }
        
        Node *slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                break;
            }
        }
        
        if(slow == fast){
            slow = head;
            
            if(slow == fast){
                while(fast -> next != slow){
                    fast = fast -> next;
                }
            } else {
                while(slow -> next != fast -> next){
                    slow = slow -> next;
                    fast = fast -> next;
                }
            }
            
            fast -> next = NULL;
        }
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
    s.removeLoop(head);
    
    printList(head);
    
    return 0;
}