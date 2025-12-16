/* 
Date: December 16, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/merge-two-sorted-linked-lists)
-----------------------------------------------------------
Problem Statement: 
Given the head of two sorted linked lists consisting of nodes respectively. Merge both lists and return the head of the sorted merged list.
-----------------------------------------------------------
Approach:
A dummy node is used to simplify handling of the merged list’s head, and a tail pointer tracks the last node of the merged list. Both linked lists are traversed together, and at each step the node with the smaller value is attached to the tail, after which the corresponding list pointer and the tail pointer are moved forward. Once one list becomes empty, the remaining nodes of the other list are directly linked to the merged list since they are already sorted. Finally, the node following the dummy node is returned as the head of the merged sorted linked list.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

# include <iostream>
# include <string>
#include <sstream>

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
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(-1), *tail = &dummy;
        
        while(head1 != NULL && head2 != NULL){
            Node *curr;
            if(head1 -> data <= head2 -> data){
                tail -> next = head1;
                head1 = head1 -> next;
            } else {
                tail -> next = head2;
                head2 = head2 -> next;
            }
            
            tail = tail -> next;
        }
        
        while(head1 != NULL){
            tail -> next = head1;
            tail = head1;
            head1 = head1 -> next;
        }
        
        while(head2 != NULL){
            tail -> next = head2;
            tail = head2;
            head2 = head2 -> next;
        }
        
        return dummy.next;
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

int main(){
    Node *head1 = NULL, *tail1;
    cout << "Enter the elements of first sorted linked list (space separated):" << endl;
    string input1;
    getline(cin, input1);
    stringstream ss1(input1);
    int x;
    while(ss1 >> x){
        Node* newNode1 = new Node(x);

        if(head1 == NULL){
            head1 = newNode1;
            tail1 = newNode1;
        } else {
            tail1 -> next = newNode1;
            tail1 = newNode1;
        }
    }

    Node *head2 = NULL, *tail2;
    cout << "Enter the elements of second sorted linked list (space separated):" << endl;
    string input2;
    getline(cin, input2);
    stringstream ss2(input2);
    while(ss2 >> x){
        Node* newNode2 = new Node(x);

        if(head2 == NULL){
            head2 = newNode2;
            tail2 = newNode2;
        } else {
            tail2 -> next = newNode2;
            tail2 = newNode2;
        }
    }

    cout << "First Linked List:" << endl;
    printList(head1);
    cout << "Second Linked List:" << endl;
    printList(head2);
    

    Solution s;
    Node *head = s.sortedMerge(head1, head2);

    cout << "Merged Sorted Linked List from above:" << endl;
    printList(head);
    
    return 0;
}