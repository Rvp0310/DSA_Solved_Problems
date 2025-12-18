/* 
Date: December 17, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/clone-a-linked-list-with-next-and-random-pointer)
-----------------------------------------------------------
Problem Statement: 
Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list.

NOTE : Original linked list should remain unchanged.
Each node of the linked list is represented as a pair of [val, random_index] where:

 - val represents node->data.
 - random_index (1-based index) represents the index of the node that the random pointer of the current node points to, or NULL if it does not point to any node.
-----------------------------------------------------------
Approach:
A new node is created for each original node and placed immediately after it in the same linked list. This keeps every original node and its copy side by side. Using this arrangement, the random pointer of each copied node is set by following the random pointer of the original node and moving to its adjacent copy. After all random pointers are fixed, the mixed list is separated into two lists: the original list is restored to its initial form, and the copied nodes are linked together to form the cloned list. The final head of the copied list is then returned, with all next and random pointers correctly pointing only within the cloned list.
-----------------------------------------------------------
Time Complexity: O(n + m)
Space Complexity: O(1)
*/

# include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        if(!head){
            return NULL;
        }
        
        Node *curr = head;
        // inserting copies of node in the list as org[i] -> copy[i] -> org[i + 1] ...
        while(curr != NULL){
            Node *copy = new Node(curr -> data);
            copy -> next = curr -> next;
            curr -> next = copy;
            curr = copy -> next;
        }
        
        curr = head;
        // assigning random pointer of copies to accurate copies using the interweave-structure
        while(curr != NULL){
            if (curr -> random){
                curr -> next -> random = curr -> random -> next;
            }
            curr = curr -> next -> next;
        }
        
        Node *newHead = head -> next;
        curr = head;
        // separating original and clone
        while(curr != NULL){
            Node *copy = curr -> next;
            curr -> next = copy -> next;
            if (copy -> next){
                copy -> next = copy -> next -> next;
            }
            curr = curr -> next;
        }
        
        return newHead;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << "Data: " << node->data;
        if (node->random)
            cout << ", Random: " << node->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        node = node->next;
    }
}


int main() {
    // Creating nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // random pointers
    n1->random = n3;   // 1 → 3
    n2->random = n1;   // 2 → 1
    n3->random = n4;   // 3 → 4
    n4->random = n2;   // 4 → 2

    cout << "Original List:\n";
    printList(n1);

    Solution s;
    Node* clonedHead = s.cloneLinkedList(n1);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    return 0;
}